#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	int n, m, a, b; cin >> n >> m >> a >> b;
	char grid[m][n];
	int dist[m][n];
	memset(dist, -1, sizeof dist);

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	map<pii, bool> visited;
	queue<pii> bfsq; bfsq.push({0, 0});
	dist[0][0] = 0;
	

	while(!bfsq.empty()) {
		pii curr = bfsq.front(); bfsq.pop();
		visited[curr] = true;
		for(int i = -1; i <= 1; i += 2) {
			pii newLoc = {curr.first + i, curr.second};
			if(newLoc.first < 0 || newLoc.first >= m) continue;
			if(grid[newLoc.first][newLoc.second] == '#') continue;
			if(visited[newLoc]) continue;

			bfsq.push(newLoc);
			visited[newLoc] = true;
			dist[newLoc.first][newLoc.second] = dist[curr.first][curr.second] + 1;
		}
		for(int i = -1; i <= 1; i += 2) {
			pii newLoc = {curr.first, curr.second + i};
			if(newLoc.second < 0 || newLoc.second >= n) continue;
			if(grid[newLoc.first][newLoc.second] == '#') continue;
			if(visited[newLoc]) continue;

			bfsq.push(newLoc);
			visited[newLoc] = true;
			dist[newLoc.first][newLoc.second] = dist[curr.first][curr.second] + 1;
		}
	}

	if(dist[m-1][n-1] == -1) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	int end = dist[m-1][n-1];

	int ans = (end/2) * a + (end % 2 == 0 ? end / 2 : end / 2 + 1) * b;

	cout << ans << endl;
	
	return 0;
}