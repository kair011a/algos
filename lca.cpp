vector<int> g[mxN];
int n, m, timer;
int tin[mxN], tout[mxN], up[mxN][32];

void precalc(int v, int p){
	tin[v]=++timer;
	up[v][0]=p;
	for(int i=1;i<=30;i++) up[v][i]=up[up[v][i-1]][i-1];
	for(int i=0;i<(int)g[v].size();i++){
		int to=g[v][i];
		if(to==p) continue;
		precalc(to,v);
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
