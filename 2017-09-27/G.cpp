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
		int n; cin >> n;
		vector<int> vals(n);

		for(int i = 0; i < n; i++) {
			cin >> vals[i];
		}
		int ans = 0;
		int curMax = 0;
		vector<bool> prev(n, false), post(n, false);
		for(int i = 0; i < n; i++) {
			if(vals[i] >= curMax) {
				prev[i] = true;
			}
			curMax = max(vals[i], curMax);
		}

		int curMin = 1e7;
		for(int i = n-1; i >= 0; i--) {
			if(vals[i] <= curMin) {
				post[i] = true;
			}
			curMin = min(vals[i], curMin);
		}

		for(int i = 1; i < n-1; i++) {
			if(prev[i] && post[i]) ans++;
		}
		cout << ans << endl;
	}
	
	return 0;
}