#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int memo[2001];

int a, k;

int dp(int n) {
	if(n == 1) {
		return 0;
	} else if (memo[n] != -1) {
		return memo[n];
	}

	int best = 100000;
	for(int i = 1; i <= k; i++) {
		best = min(best, max(dp(i) - 1, dp(n-i)));
		if(i == n-1) break;
	}
	return memo[n] = best + 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(memo, -1, sizeof memo);
	
	cin >> a >> k;
	if(a == k) {
		if(a == 1) {
			cout << 0 << endl;
		} else {
			cout << -1 << endl;
		}
	} else {
		cout << dp(a) << endl;
	}
	return 0;
}