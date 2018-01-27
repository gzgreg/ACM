#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000003

ll fact[1000001];
ll inv[1000001];

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
	ll ans = fact[n]*inv[r];
	ans %= MOD;
	ans *= inv[n-r];
	ans %= MOD;
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for(int i = 0; i <= 1000000; i++) {
		if(i == 0) {
			fact[i] = 1;
			inv[i] = 1;
		} else {
			fact[i] = fact[i-1] * i % MOD;
			inv[i] = inv[i-1] * mod_pow(i, MOD - 2) % MOD;
		}
	}

	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;

		int halfN = (n / 2) + (n % 2);

		ll ans = 0;
		ans += nCr(n, halfN);
		ans -= nCr(max(m, n-m), halfN);
		ans += 2;
		ans += MOD;
		ans %= MOD;
		cout << ans << endl;
	}
	
	return 0;
}