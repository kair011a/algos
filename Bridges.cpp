const int mxN=1e5+7;
vector<int> g[mxN];
bool used[mxN];
timer, tin[mxN], fup[mxN];
 
void dfs (int v, int p = -1) {
	used[v] = 1;
	tin[v] = fup[v] = timer++;
	for(int to:g[v]) {
    if (to == p)  continue;
		if (used[to]) fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] > tin[v]) {
				IS_BRIDGE(v,to);
      }
		}
	}
}
 
void find_bridges() {
	timer = 0;
	for (int i=0; i<n; i++) {
		used[i] = 0;
  }
	for (int i=0; i<n; i++){
		if (!used[i]) {
			dfs (i);
    }
  }
} 
 
