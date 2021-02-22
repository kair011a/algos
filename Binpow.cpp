#define ll long long 
const ll mod=1e9+7;

ll binpow (int a, int n) {
	if (n == 0) return 1;
	if (n % 2 == 1) return binpow (a, n-1) * a % mod;
	else {
		ll b = binpow (a, n/2) % mod;
		return b * b;
	}
}
