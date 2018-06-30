#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000000007

ll fact[100001];
ll inv[100001];

long long mod_pow(long long base, long long exp) {
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
	ll ans = fact[n] * inv[r];

	ans %= MOD;
	ans *= inv[n-r];
	ans %= MOD;
	
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;

	fact[0] = 1;
	inv[0] = 1;
	for(int i = 1; i <= 100000; i++) {
		fact[i] = fact[i-1] * i % MOD;
		inv[i] = inv[i-1] * mod_pow(i, MOD-2) % MOD;
	}

	while(T--) {
		int a, b; cin >> a >> b;

		cout << ((2*nCr(a-1, b)) % MOD) << endl;
	}
	
	return 0;
}