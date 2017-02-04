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

	int T; cin >> T;

	for(int id = 1; id <= T; id++) {
		cout << "Case #" << id << ": ";

		int N, M; cin >> N >> M;

		int totSize = 0;
		int maxSize = 0;
		for(int i = 0; i < N; i++) {
			int curr; cin >> curr; totSize += curr; maxSize = max(maxSize, curr);
		}

		ll ans = 1;
		if(totSize > M) {
			cout << 0 << endl;
			continue;
		}
		for(int i = 2; i <= N; i++) {
			ans *= i;
			ans %= MOD;
		}
		cout << ans << endl;
		ans *= nCr(M + N + 1 - totSize, N); ans %= MOD;

		cout << ans << endl;
	}
	
	return 0;
}