#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	
	int T; cin >> T;

	while(T--) {
		int n; cin >> n;
		vector<pii> p;

		vector<vector<double>> dp (151, vector<double>(151, 0));

		for(int i = 0; i < n; i++) {
			int si, pi; cin >> si >> pi; p.push_back({si, pi});
		}

		dp[0][0] = 1;

		for(int i = 1; i <= n; i++) {
			pii currParty = p[i-1];

			for(int j = 0; j <= 150; j++) {
				dp[i][j] = dp[i-1][j];
				if(currParty.first <= j) {
					dp[i][j] = max(dp[i][j], dp[i-1][j-currParty.first] * currParty.second / 100);
				}
			}
		}
		double bestAns = 0;
		for(int i = 76; i <= 150; i++) {
			bestAns = max(bestAns, dp[n][i]);
		}
		cout << fixed << setprecision(6) << bestAns * 100 << endl;
	}

	return 0;
}