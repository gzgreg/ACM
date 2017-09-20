#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int memo[1000001];

int dp(int k) {
	if(k == 1) {
		return 1;
	} else if (memo[k] != -1) {
		return memo[k];
	}
	int ans = 0;
	for(int i = 2; i < sqrt(k) + 0.01; i++) {
		if(k % i == 0) {
			ans += dp(k / i);
			if(i*i != k) {
				ans += dp(i);
			}
		}
	}
	ans += dp(1);
	return memo[k] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(memo, -1, sizeof memo);
	int k; cin >> k;
	cout << dp(k) << endl;
	
	return 0;
}