#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000000007

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		vector<ll> vals(n);
		for(int i = 0; i < n; i++) {
			cin >> vals[i];
		}

		vector<ll> dp(n+1, 0);
		for(int i = 1; i <= n; i++) {
			dp[i] = dp[i-1] + vals[i-1];
			dp[i] %= MOD;
			dp[i] += dp[i-1] * vals[i-1];
			dp[i] %= MOD;
		}

		cout << dp[n] << endl;
	}
	
	return 0;
}