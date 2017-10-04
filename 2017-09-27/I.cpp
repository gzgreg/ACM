#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T; cin >> T;
	while(T--) {

		int n; cin >> n;

		vector<int> vals;
		map<int, int> colors;
		vector<int> nxtJmp(n, -1);
		for(int i = 0; i < n; i++) {
			int cur; cin >> cur; vals.push_back(cur);
			if(colors.count(cur)) {
				nxtJmp[i] = colors[cur];
			}

			colors[cur] = i;
		}

		vector<int> dp(n+1, 0);

		for(int i = 1; i < n+1; i++) {
			int ans = dp[i-1] + 1;
			if(nxtJmp[i-1] != -1) {
				ans = min(ans, dp[nxtJmp[i-1] + 1] + 1);
			}
			dp[i] = ans;
		}
		cout << dp[n] - 1 << endl;
	}
	
	return 0;
}