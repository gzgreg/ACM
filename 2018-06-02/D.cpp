#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int memo[10001][7];

vector<vector<int>> cnt = {{}, {2, 3, 4, 5}, {1, 3, 4, 6}, {1, 2, 5, 6},
							{1, 2, 5, 6}, {1, 3, 4, 6}, {2, 3, 4, 5}};

int dp(int n, int side) {
	if(n == 0) return 0;
	if(n < 0) return 1e9;
	if(memo[n][side] != -1) return memo[n][side];
	int ans = 1e9;
	for(auto cur : cnt[side]) {
		ans = min(ans, dp(n-cur, cur) + 1);
	}
	return memo[n][side] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(memo, -1, sizeof memo);

	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		if(dp(n, 1) < 1e8) cout << dp(n, 1) << endl;
		else cout << -1 << endl;
	}
	
	return 0;
}