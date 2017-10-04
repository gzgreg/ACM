#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll factorial(int n) {
	ll ans = 1;
	for(int i = 1; i <= n; i++) {
		ans *= i;
	}
	return ans;
}
//
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;

	while(T--) {
		int n; cin >> n;
		string s; cin >> s;

		vector<int> counts(26, 0);
		for(char cur : s) {
			counts[cur - 'a']++;
		}
		int numOdds = 0;
		ll ans = factorial(n/2);

		for(int i : counts) {
			if(i % 2) {
				numOdds++;
				ans /= factorial(i / 2);
			} else {
				ans /= factorial(i / 2);
			}
		}
		if(numOdds > 1) {
			cout << 0 << endl;
		} else {
			cout << ans << endl;
		}
	}
	
	return 0;
}