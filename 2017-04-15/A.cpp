#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dp[555555], dp2[555555];

int solve(vector<pair<pii, int>> pos, vector<pair<pii, int>> neg) {
	memset(dp, -1, sizeof dp);
	memset(dp2, -1, sizeof dp2);
	dp[0] = 0;
	dp2[0] = 0;
	for(auto curr : pos) {
		// cout << curr.first.first << " " << curr.first.second << " " << curr.second << endl;
		for(int i = 100000; i >= 0; i--) {
			if(-curr.first.first > i) break;
			if(dp[i] != -1) {
				dp[i + curr.first.second] = max(dp[i + curr.first.second],
											dp[i] + curr.second);
			}
		}
	}
	// for(int i = 0; i < 100; i++) {
	// 	cout << dp[i] << " ";
	// }
	// cout << endl;
	for(auto curr : neg) {
		// cout << curr.first.first << " " << curr.first.second << " " << curr.second << endl;
		for(int i = 100000; i >= 0; i--) {
			if(-curr.first.first > i) break;
			if(dp2[i] != -1) {
				dp2[i + curr.first.second] = max(dp2[i + curr.first.second],
											dp2[i] + curr.second);
			}
		}
	}
	int ans = 0;
	// for(int i = 0; i < 10; i++) {
	// 	cout << dp[i] << " " << dp2[i] << endl;
	// }
	for(int i = 0; i <= 100000; i++) {
		if(dp[i] == -1 || dp2[i] == -1) continue;
		ans = max(ans, dp[i] + dp2[i]);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;

	vector<pair<pii, int>> pos, neg, pos2, neg2;

	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		int currTot = 0, minTot = 0;
		for(char c : s) {
			if(c == '(') {
				currTot++;
			} else {
				currTot--;
			}
			minTot = min(minTot, currTot);
		}

		if(currTot > 0) {
			pos.push_back({{minTot, currTot}, s.size()});
		} else {
			currTot = 0, minTot = 0;
			reverse(s.begin(), s.end());
			for(char c : s) {
				if(c == '(') {
					currTot--;
				} else {
					currTot++;
				}
				minTot = min(minTot, currTot);
			}
			neg.push_back({{minTot, currTot}, s.size()});
		}
	}

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	// int ans = solve(pos, neg);
	reverse(pos.begin(), pos.end());
	// ans = max(ans, solve(pos, neg));
	reverse(neg.begin(), neg.end());
	// reverse(pos.begin(), pos.end());
	// ans = max(ans, solve(pos, neg));

	cout << solve(pos, neg) << endl;
	return 0;
}