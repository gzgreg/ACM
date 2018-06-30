#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000000007

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

ll nCr(ll n, ll r) {
	ll ans = 1;
	for(int i = n; i > n - r; i--) {
		ans *= i;
		ans %= MOD;
	}
	for (int i = 1; i <= r; i++) {
		ans *= mod_pow(i, MOD-2);
		ans %= MOD;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m; cin >> n >> m;

	if(n > m) cout << 0 << endl;
	else cout << nCr(m, n) << endl;
	
	return 0;
}