#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000000009

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n; cin >> n;

	if(n == 1) {
		cout << 0 << endl;
	} else if (n == 2){
		cout << 2 << endl;
	} else {
		ll ans = 1, sub = 1, plus = 1;
		for(int i = 0; i < n; i++) {
			ans *= 3;
			ans %= MOD;
			
			sub *= 2;
			sub %= MOD;
		}

		ans -= sub;
		ans += MOD;
		ans %= MOD;
		ans -= sub;
		ans += MOD;
		ans %= MOD;
		ans += plus;
		ans %= MOD;
		cout << ans << endl;
	}

	return 0;
}