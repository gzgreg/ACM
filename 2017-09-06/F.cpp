#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int memo[101][101][2];

int dp(int n, int k, bool last) {
	if(n == 0) {
		return k == 0;
	} else if (memo[n][k][last] != -1) {
		return memo[n][k][last];
	}

	int ans = 0;
	if(last) {
		ans += dp(n-1, k-1, 1);
		ans += dp(n-1, k, 0);
	} else {
		ans += dp(n-1, k, 1);
		ans += dp(n-1, k, 0);
	}
	return memo[n][k][last] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int P; cin >> P;

	memset(memo, -1, sizeof memo);

	while(P--) {
		int junk, n, k; cin >> junk >> n >> k;

		cout << junk << " " << dp(n, k, 0) << endl;
	}
	
	return 0;
}