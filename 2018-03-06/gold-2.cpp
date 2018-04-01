#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1000000007;

vector<int> colors;
vector<int> par;
vector<vector<int>> adj;
ll memo[100002][4];

ll dp(int node, int color) {
	if(memo[node][color] != -1) {
		return memo[node][color];
	}
	if(colors[node] != 0) {
		if(colors[node] != color) {
			return 0;
		}
	}

	ll ans = 1;
	for(auto cur : adj[node]) {
		if(par[node] == cur) {
			continue;
		}
		par[cur] = node;
		ll curAns = 0;
		for(int j = 1; j <= 3; j++) {
			if(j == color) continue;
			curAns += dp(cur, j);
			curAns %= MOD;
		}
		ans *= curAns;
		ans %= MOD;
	}

	return memo[node][color] = ans;
}

int main(){
	freopen("barnpainting.in", "r", stdin);
	freopen("barnpainting.out", "w", stdout);
	memset(memo, -1, sizeof memo);
	int N, K; cin >> N >> K;

	par = vector<int>(N);
	colors = vector<int>(N);
	adj = vector<vector<int>>(N);

	for(int i = 0; i < N-1; i++) {
		int x, y; cin >> x >> y;
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for(int i = 0; i < K; i++) {
		int b, c; cin >> b >> c; b--;
		colors[b] = c;
	}
	
	cout << ((dp(0, 1) + dp(0, 2) + dp(0, 3)) % MOD) << endl;

	return 0;
}