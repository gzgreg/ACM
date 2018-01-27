#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000003

int n, m;
ll memo[1001][1001];

ll dp(int i, int c) {
	if(i == n) {
		return 1;
	} else if (memo[i][c] != -1) {
		return memo[i][c];
	}
	memo[i][c] = dp(i+1, c)*(c-(i != 0)) % MOD;
	if(c < m) {
		memo[i][c] += dp(i+1, min(m, c+1));
		memo[i][c] %= MOD;
	}
	return memo[i][c];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T; cin >> T;
	while(T--) {
		memset(memo, -1, sizeof memo);
		cin >> n >> m;
		cout << dp(0, 0) << endl;
		// for(int i = 0; i <= n; i++) {
		// 	for(int j = 0; j <= m; j++) {
		// 		cout << memo[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
	}

	return 0;
}