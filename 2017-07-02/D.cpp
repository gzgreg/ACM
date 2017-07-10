#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000000007

vector<ll> memo(5e6 + 2, -1);
vector<bool> primes (5e6+1, true);
vector<ll> primeList;

void calcPrimes() {
	for(int i = 2; i < 3000; i++) {
		if(primes[i]) {
			primeList.push_back(i);
			int curr = 2*i;
			while(curr <= 5000000) {
				primes[curr] = false;
				curr += i;
			}
		}
	}
}

ll prime(ll val) {
	if(primes[val]) return -1;
	for(int i : primeList) {
		if(val % i == 0) {
			return i;
		}
	}
}

ll dp(ll i) {
	if (memo[i] != -1) {
		return memo[i];
	}
	ll smallFac = prime(i);
	if(smallFac == -1 || smallFac == i) {
		return memo[i] = i*(i-1)/2 % MOD;
	}
	ll ans = (ll) i/smallFac*dp(smallFac);
	ans %= MOD;
	ans += dp(i/smallFac);
	ans %= MOD;
	return memo[i] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	calcPrimes();
	ll t, l, r; cin >> t >> l >> r;
	ll power = 1;
	ll ans = 0;
	for(int i = l; i <= r; ++i) {
		ans += dp(i)*power;
		ans %= MOD;
		power *= t;
		power %= MOD;
	}
	cout << ans << endl;

	return 0;
}