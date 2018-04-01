#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 2147483647

vector<int> data;

ll memo[2010][2010];

ll dp(int id, int left) {
	if(id == data.size() - 1) {
		return 1;
	} else if(memo[id][left] != -1) {
		return memo[id][left];
	}

	if(data[id+1] < min(left, data[id])) {
		return memo[id][left] = dp(id+1, max(left, data[id])) % MOD;
	} else if (data[id+1] > max(left, data[id])) {
		return memo[id][left] = dp(id+1, min(left, data[id])) % MOD;
	}
	ll ans = dp(id+1, min(left, data[id]));
	ans += dp(id+1, max(left, data[id]));
	ans %= MOD;
	return memo[id][left] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(memo, -1, sizeof memo);

	int N; cin >> N;
	for(int i = 0; i < N+1; i++) {
		int cur; cin >> cur; data.push_back(cur);
	}

	cout << dp(1, data[0]) << endl;
	
	return 0;
}