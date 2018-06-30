#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while(T--) {
		ll l, r; cin >> l >> r;
		if(r < 10) {
			cout << -1 << endl;
			continue;
		}
		l = max(l, 10LL);
		bool found = false;
		ll ans = 0;
		for(ll i = r; i >= l; i--) {
			ll power = log10(i) + 1 + 1e-10;
			ll num = 1;
			for(int i = 0; i < power / 2; i++) {
				num *= 10;
			}

			ll num1 = i / num;
			ll num2 = i - num1 * num;
			if(num1 == 0 || num2 == 0) continue;
			if(__gcd(num1, num2) == 1) {
				found = true;
				ans = i;
				break;
			}
		}
		if(found) cout << ans << endl;
		else cout << -1 << endl;
	}
	
	return 0;
}