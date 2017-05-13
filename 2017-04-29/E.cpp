#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	int n, w, h, l; cin >> n >> w >> h >> l;
	char grid[h][w];
	vector<pii> startState (1, {0, 0});
	pii endLoc;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> grid[i][j];
			if(grid[i][j] == '1') {
				startState[0] = {i, j};
			} else if (grid[i][j] == '2'
						|| grid[i][j] == '3'
						|| grid[i][j] == '4') {
				startState.push_back({i, j});
			} else if (grid[i][j] == 'X') {
				endLoc = {i, j};
			}
		}
	}
	sort(++(startState.begin()), startState.end());

	queue<vector<pii>> bfsq; bfsq.push(startState);
	set<vector<pii>> visited; visited.insert(startState);
	map<vector<pii>, int> dist; dist[startState] = 0;

	while(!bfsq.empty()) {
		auto curr = bfsq.front(); bfsq.pop();
		// for(pii c : curr) {
		// 	cout << c.first << " " << c.second << " ";
		// }
		// cout << endl;
		if(curr[0] == endLoc) {
			cout << dist[curr] << endl;
			return 0;
		}
		if(dist[curr] > l) {
			cout << "NO SOLUTION" << endl;
			return 0;
		}
		for(int id = 0; id < curr.size(); id++) {
			pii loc = curr[id];
			for(int i = loc.first; i >= 0; i--) {
				bool blocked = false;
				pii nextLoc = {i, loc.second};
				for(pii other : curr) {
					if(other == loc) continue;
					if(other.first == i-1 
						&& other.second == nextLoc.second) {
						blocked = true;
						break;
					}
				}
				if(i == 0 || grid[i-1][loc.second] == 'W' || blocked) {
					vector<pii> newState (curr);
					newState[id] = nextLoc;
					sort(++(newState.begin()), newState.end());
					if(!visited.count(newState)) {
						visited.insert(newState);
						dist[newState] = dist[curr] + 1;
						bfsq.push(newState);
					}
					break;
				}
			}
			for(int i = loc.first; i < h; i++) {
				bool blocked = false;
				pii nextLoc = {i, loc.second};
				for(pii other : curr) {
					if(other == loc) continue;
					if(other.first == i+1
						&& other.second == nextLoc.second) {
						blocked = true;
						break;
					}
				}
				if(i == h-1 || grid[i+1][loc.second] == 'W' || blocked) {
					vector<pii> newState (curr);
					newState[id] = nextLoc;
					sort(++(newState.begin()), newState.end());
					if(!visited.count(newState)) {
						visited.insert(newState);
						dist[newState] = dist[curr] + 1;
						bfsq.push(newState);
					}
					break;
				}
			}
			for(int i = loc.second; i >= 0; i--) {
				bool blocked = false;
				pii nextLoc = {loc.first, i};
				for(pii other : curr) {
					if(other == loc) continue;
					if(other.first == nextLoc.first 
						&& other.second == i-1) {
						blocked = true;
						break;
					}
				}
				if(i == 0 || grid[loc.first][i-1] == 'W' || blocked) {
					vector<pii> newState (curr);
					newState[id] = nextLoc;
					sort(++(newState.begin()), newState.end());
					if(!visited.count(newState)) {
						visited.insert(newState);
						dist[newState] = dist[curr] + 1;
						bfsq.push(newState);
					}
					break;
				}
			}
			for(int i = loc.second; i < w; i++) {
				bool blocked = false;
				pii nextLoc = {loc.first, i};

				for(pii other : curr) {
					if(other == loc) continue;
					if(other.first == nextLoc.first 
						&& other.second == i+1) {
						blocked = true;
						break;
					}
				}
				if(i == w-1 || grid[loc.first][i+1] == 'W' || blocked) {
					vector<pii> newState (curr);
					newState[id] = nextLoc;
					sort(++(newState.begin()), newState.end());
					if(!visited.count(newState)) {
						visited.insert(newState);
						dist[newState] = dist[curr] + 1;
						bfsq.push(newState);
					}
					break;
				}
			}
		}
		
	}
	cout << "NO SOLUTION" << endl;
	return 0;
}