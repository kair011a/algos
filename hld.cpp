vector<int> g[mxN];
int n, m, timer, Id=1;
int tin[mxN], tout[mxN], up[mxN][32], head[128],siz[128];
struct chain{
	int pos, id, sz;
} c[mxN];

void hld(int v, int p){
	if(head[Id]==0){
		head[Id]=v;
	}
	c[v].pos=siz[Id];
	c[v].id=Id;
	siz[Id]++;
	int big=-1, u=-1;
	for(int i=0;i<(int)g[v].size();i++){
		int to=g[v][i];
		if(to!=p and c[to].sz>big) {
			big=c[to].sz, u=to;
		}
	}
	if(big!=-1) hld(u,v);
	for(int i=0;i<(int)g[v].size();i++){
		int to=g[v][i];
		if(to!=p&&to!=u) {
			Id++;
			hld(to,v);
		}
	}
}
void precalc(int v, int p){
	tin[v]=++timer;
	c[v].sz=1;
	up[v][0]=p;
	for(int i=1;i<=30;i++) up[v][i]=up[up[v][i-1]][i-1];
	for(int i=0;i<(int)g[v].size();i++){
		int to=g[v][i];
		if(to==p) continue;
		precalc(to,v);
		c[v].sz+=c[to].sz;
	}
	tout[v]=++timer;
}
bool upper(int a, int b) {
	return tin[a]<=tin[b]&&tout[b]<=tout[a];
}
int lca(int a, int b){
	if(upper(a, b)) return a;
	if(upper(b, a)) return b;
	for(int i=30;i>=0;i--){
		if(!upper(up[a][i], b)&&tin[up[a][i]]) {
			a=up[a][i];
		}
	}
	return up[a][0];
}
vector<pii> getpath(int a, int b){
	vector<pii> q;
	int v=a, lc=lca(a,b);
	while(1){
		if(upper(head[c[v].id],lc)) {
			q.pb({v,lc}); break;
		}
		else q.pb({v,head[c[v].id]});
		v=up[head[c[v].id]][0];
		if(v==lc) break;
	}
	v=b;
	while(1){
		if(upper(head[c[v].id],lc)) {
			q.pb({v,lc}); break;
		}
		else q.pb({v,head[c[v].id]});
		v=up[head[c[v].id]][0];
		if(v==lc) break;
	}
	return q;
}
