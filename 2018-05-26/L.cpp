#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000000007

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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, k; cin >> n >> k;
	
	if(k == 0) {
		cout << (mod_pow(2, n) - 1 + MOD) % MOD << endl;
		return 0;
	}

	ll numRings = (n + k) / (k+1);
	ll topRing = n % (k+1);

	ll ans = mod_pow(2, numRings);
	ans--;
	ans += MOD;
	ans %= MOD;

	ans *= (2*(k+1) - 1);
	ans %= MOD;
	//cout << ans << " " << numRings << " " << topRing << endl;
	if(topRing != 0) {
		ll numMovesTopRing = mod_pow(2, numRings - 1);
		//cout << numMovesTopRing << endl;
		ll extra = numMovesTopRing * (2*(k+1) - 2*topRing);
		ans -= extra;
		ans += MOD * (extra / MOD + 1);
		ans %= MOD;
	}

	cout << ans << endl;

	return 0;
}