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
		int n, s; cin >> n >> s;
		if(n == 1 && s == 1) {
			cout << 1 << endl;
			continue;
		}

		if(s > 9*n || s < 2) {
			cout << -1 << endl;
			continue;
		}
		if(n % 2 == 0 && s % 2 == 1) {
			cout << -1 << endl;
			continue;
		}

		string ans(n, ' ');

		for(int i = 0; i < n / 2; i++) {
			int curDigit = min(9, s / 2);
			s -= 2 * curDigit;
			ans[i] = curDigit + '0';
			ans[n-i-1] = curDigit + '0';
		}

		if(n % 2 == 1) ans[n / 2] = s + '0';

		cout << ans << endl;
	}
	
	return 0;
}