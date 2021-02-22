const int mxN=1e7;
int p[mxN+1];

for (int i = 2; i <= N; i ++) {
  if (!p[i]) {
    for (ll j = (i * 1LL * i); j <= N; j += i) {
      p[j] = 1;	
    }
  }
}
// p[i] = 0 when i Prime 
