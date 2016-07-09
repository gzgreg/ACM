#include <bits/stdc++.h>

using namespace std;

double dp[1000][6000];

double solve(int n, int k){
	if(n < 0 || k < 0){
		return 0;
	} else if(abs(dp[n][k] + 1) > 0.01){
		return dp[n][k];
	} else if(n == 0 && k != 0){
		dp[n][k] = 0;
		return 0;
	} else if(n != 0 && k == 0){
		dp[n][k] = 0;
		return 0;
	} else {
		dp[n][k] = (solve(n-1, k-1) + solve(n-1, k-2) + solve(n-1, k-3) + solve(n-1, k-4) + solve(n-1, k-5) + solve(n-1, k-6)) / 6;
		return dp[n][k];
	}
}

int main(){
	ios::sync_with_stdio(0);
	int t; cin >> t;
	memset(dp, -1, sizeof dp);
	while(t--){
		int n, k; cin >> n >> k;
		if(n >= 550 || k >= 3300 || n*6 < k || n > k){
			cout << 0 << endl;
			continue;
		}
		dp[0][0] = 1;
		cout << (int) (solve(n, k)* 100) << endl;
	}
	return 0;
}