int n; 
vector<int> g[mxN];
bool used[MAXN];
vector<int> ts;
 
void dfs (int v) {
	used[v] = 1;
	for(int to:g[v]){
		if (!used[to]){
			dfs (to);
		}
	}
	ts.push_back(v);
}
 
void topsort() {
	for (int i=0; i<n; i++){
		used[i] = 0;
	}
	ts.clear();
	for (int i=0; i<n; i++){
		if (!used[i]){
			dfs(i);
		}
	}
	reverse(ts.begin(), ts.end());
}
