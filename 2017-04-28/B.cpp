
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m; 
vector<vector<char>> grid;
pii start, endloc;

int memo[1000][1000][4];
bool dfs(pii loc, int turns, int dir) {
	if(loc == endloc) return true;
	memo[loc.first][loc.second][dir] = turns;
	vector<pii> next;
	next.push_back({loc.first - 1, loc.second});
	next.push_back({loc.first + 1, loc.second});
	next.push_back({loc.first, loc.second - 1});
	next.push_back({loc.first, loc.second + 1});
	for(int i = 0; i < 4; i++) {
		pii nextLoc = next[i];
		if(i != dir && turns == 0) continue;
		if(nextLoc.first < 0 || nextLoc.first >= n) continue;
		if(nextLoc.second < 0 || nextLoc.second >= m) continue;
		if(grid[nextLoc.first][nextLoc.second] == '*') continue;
		int turnDiff = 0;
		if(i != dir) turnDiff = 1;
		if(memo[nextLoc.first][nextLoc.second][i] >= turns-turnDiff) continue;
		if(dfs(nextLoc, turns - turnDiff, i)) return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin >> n >> m;
	memset(memo, -1, sizeof memo);
	grid = vector<vector<char>> (n, vector<char> (m, ' '));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			char curr; cin >> curr; 
			if(curr == 'S') {
				start = {i, j};
			} else if (curr == 'T') {
				endloc = {i, j};
			}
			grid[i][j] = curr;
		}
	}	
	for(int i = 0; i < 4; i++) {
		if(dfs(start, 2, i)) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

	return 0;
}