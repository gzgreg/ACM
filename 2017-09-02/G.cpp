#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int memo[10001][26];

vector<vector<int>> vals(26);

int K;

int dp(int i, int c) {
	if(i == 0 || i == 1) {
		return 0;
	} else if (memo[i][c] != -1) {
		return memo[i][c];
	}

	int bestAns = 1e9;

	for(int id = 0; id < 26; id++) {
		bestAns = min(bestAns, dp(i-1, id) + vals[id][c]);
	}
	return memo[i][c] = bestAns;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> K;

	memset(memo, -1, sizeof memo);

	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < 26; j++) {
			int cur; cin >> cur; vals[i].push_back(cur);
		}
	}
	int bestAns = 1e9;
	for(int i = 0; i < 26; i++) {
		bestAns = min(bestAns, dp(K, i));
	}

	cout << bestAns << endl;

	return 0;
}