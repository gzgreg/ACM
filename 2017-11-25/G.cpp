#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> pillars (50);
vector<int> cumsum(51);

set<int> memo[50][500];
bool vis[50][100];

int N;

set<int> dp(int h, int w) {
	if(h == 50) {
		return {0};
	} else if (vis[h][w]) {
		return memo[h][w];
	}
	set<int> ans;
	int maxWidth = w;
	if(N - cumsum[h] < 2) {
		maxWidth = -1;
		ans = {0};
	}
	int minWidth = N - cumsum[h];
	int tmp = h;
	while(cumsum[tmp] == cumsum[h]) tmp++;
	if(cumsum[tmp] == N) minWidth = w;
	for(int i = minWidth; i <= maxWidth; i++) {
		set<int> cur = dp(h+1, i);
		for(auto val : cur) {
			ans.insert(val + max(0, i - (N - cumsum[h])));
		}
	}

	cout << h << " " << w << " ";
	for(auto cur : ans) {
		cout << cur << " ";
	}
	cout << endl;

	vis[h][w] = true;
	memo[h][w] = ans;
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	memset(vis, false, sizeof memo);

	for(int i = 0; i < N; i++) {
		int hi; cin >> hi; pillars[hi-1]++;
	}
	for(int i = 1; i <= 50; i++) {
		cumsum[i] = cumsum[i-1] + pillars[i-1];
	}
	set<int> ans = dp(1, N);

	for(auto cur : ans) {
		cout << cur << " ";
	}
	cout << endl;

	return 0;
}