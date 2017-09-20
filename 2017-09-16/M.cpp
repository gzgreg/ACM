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

	int n; cin >> n;

	vector<int> vals;
	map<int, set<int>> colors;
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; vals.push_back(cur);
		colors[cur].insert(i);
	}

	vector<int> dp(n+1, 0);

	for(int i = 1; i < n+1; i++) {
		int ans = dp[i-1] + 1;
		auto bound = colors[vals[i]].lower_bound(i);
		if(bound != colors[vals[i]].end()
			&& bound != colors[vals[i]].begin()) {
			bound--;
			//cout << i << " " << *bound << endl;
			ans = min(ans, dp[*bound] + 1);
		}
		dp[i] = ans;
	}

	cout << dp[n] - 1<< endl;
	
	return 0;
}