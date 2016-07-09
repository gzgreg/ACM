#include <bits/stdc++.h>

using namespace std;
int dp[1000][1000];

int solve(string s, int f, int l){
	if(dp[f][l] != -1){
		return dp[f][l];
	} else if (f == l){
		dp[f][l] == 1;
		return 1;
	} else if(l == f+1 && s[f] == s[l]){
		dp[f][l] == 2;
		return 2;
	} else {
		if(s[f] == s[l]){
			dp[f][l] = solve(s, f+1, l-1) + 2;
			return dp[f][l];
		} else {
			dp[f][l] = max(solve(s, f, l-1), solve(s, f+1, l));
			return dp[f][l];
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	int T; cin >> T;
	string s;
	getline(cin, s);
	while(T--){
		
		getline(cin, s);
		memset(dp, -1, sizeof dp);
		if(s.size() == 0){
			cout << 0 << endl;
			continue;
		}
		cout << solve(s, 0, s.size() - 1) << endl;
	}
	return 0;
}