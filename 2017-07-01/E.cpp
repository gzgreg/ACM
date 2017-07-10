#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> ds;
vector<int> dsrank;

int find(int s) {
	if(ds[s] != s) {
		ds[s] = find(ds[s]);
	}
	return ds[s];
}

void merge(int x, int y) {
	int xRoot = find(x);
	int yRoot = find(y);

	if(xRoot == yRoot) return;

	if(dsrank[xRoot] < dsrank[yRoot]) {
		ds[xRoot] = yRoot;
	} else if (dsrank[xRoot] > dsrank[yRoot]) {
		ds[yRoot] = xRoot;
	} else {
		ds[yRoot] = xRoot;
		dsrank[xRoot]++;
	}
}

int memo[1 << 24];

vector<vector<int>> friends (210, vector<int>(210, -1));
int dp(int mask, vector<int>& group) {
	if(mask == (1 << group.size()) - 1) {
		return 0;
	} else if (memo[mask] != -1) {
		return memo[mask];
	}
	int best = 1e9;
	for(int i = 0; i < group.size(); i++) {
		if(mask & 1 << i) continue;
		for(int j = i+1; j < group.size(); j++) {
			if(mask & 1 << j) continue;
			int curMask = mask;
			curMask = curMask | (1 << i);
			curMask = curMask | (1 << j);
			best = min(best, dp(curMask, group) + friends[group[i]][group[j]]);
		}
	}
	return memo[mask] = best;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++) {
		ds.push_back(i); dsrank.push_back(0);
	}
	for(int i = 0; i < m; i++) {
		int p, q, c; cin >> p >> q >> c;
		friends[p-1][q-1] = c;
		friends[q-1][p-1] = c;
		merge(p-1, q-1);
	}

	map<int, vector<int>> group;

	for(int i = 0; i < n; i++) {
		group[find(i)].push_back(i);
	}

	for(pair<int, vector<int>> curr : group) {
		vector<int> curGroup = curr.second;
		if(curGroup.size() % 2) {
			cout << "impossible" << endl;
			return 0;
		}
	}
	int ans = 0;
	for(pair<int, vector<int>> curr : group) {
		vector<int> curGroup = curr.second;
		memset(memo, -1, sizeof memo);
		ans += dp(0, curGroup);
	}

	cout << ans << endl;

	return 0;
}