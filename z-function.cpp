/* 
        TRIVIAL O(N^2);
*/
vector<int> z_function_trivial (string s) {
	int n = (int)s.size();
	vector<int> z (n);
 	z[0] = 0;
	for (int i=1; i<n; ++i){
		while (i + z[i] < n && s[z[i]] == s[i+z[i]]){
			z[i]++;  
    		}
  	}
	return z;
}

/*
        O(N);
*/
vector<int> Z(string s) {
	int n = (int) s.size();
	int l = 0;
	vector <int> z(n,0);
	for (int i = 1; i < n; i ++){
		z[i] = min(z[i-l], l+z[i]-i);
		z[i] = max(z[i], 0);
		while (s[z[i]] == s[i+z[i]]) {
			z[i]++;
		}
		if (i + z[i] > l + z[i]) {
			l = i;
		}
	}
	return z;
} 
