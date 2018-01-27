#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000003

long long mod_pow(long long base, long long  exp) {
	long long val = 1;
	base = base % MOD;
	
	while(exp > 0) {
		if(exp % 2 == 1) {
			val *= base;
			val %= MOD;
		}
		exp = exp / 2;
		base *= base;
		base %= MOD;
	}
	return val;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;
		cout << (mod_pow(2, n) + mod_pow(2, m) - 2 + MOD) % MOD << endl;
	}
	
	return 0;
}