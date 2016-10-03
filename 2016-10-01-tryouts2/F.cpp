#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'
#define MOD 1000000007

long long mod_pow(long long base, long long  exp) {
	long long  val = 1;
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

	int T; cin >> T;
	while(T--) {
		long long n; cin >> n;

		long long startVal = mod_pow(2, n-1) - 1;

		ll ans = startVal * n % MOD;
		ll dist = 0;
		if(n > 2) dist = mod_pow(2, n-3);
		for(int i = n-1; i > 0; i--) {
			if(i < n-1) startVal += ((n-i-1) * mod_pow(2, i - 1)) % MOD;
			startVal %= MOD;
			ans += startVal * i;
			ans %= MOD;			
		}
		cout << ans << endl;
	}
	
	return 0;
}