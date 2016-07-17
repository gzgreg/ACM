#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	while(T--) {
		int h, w, d; cin >> h >> w >> d;
		char map[h][w];
		int dist[h][w];
		memset(dist, 1000000, sizeof dist);
		int startH, startW;
		priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> dijk;
		set<pii> unvisited;
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				cin >> map[i][j];
				if(map[i][j] == 'S'){
					startH = i;
					startW = j;
					dijk.push({0, {i, j}});
				}
				
				unvisited.insert({i, j});
			}
		}

		while(!dijk.empty()) {
			pair<int, pii> curr = dijk.top(); dijk.pop();
			unvisited.erase(curr.second);
			int currDist = curr.first;
			pii coord = curr.second;
			if(coord.first == 0 || coord.first == h-1
				|| coord.second == 0 || coord.second == w-1) {
				cout << currDist + 1 << endl;
				break;
			}
			for(int x = coord.first - 1; x <= coord.first + 1; x += 2) {
				int y = coord.second;
				if(x < 0 || x >= h) continue;
				if(unvisited.find({x, y}) == unvisited.end()) continue;
				int newDist;
				if(map[x][y] == '.') {
					newDist = min(dist[x][y], currDist + 1);
				} else if (map[x][y] == '#') {
					continue;
				} else {
					newDist = min(dist[x][y], currDist + 1 + d);
				}
				if(dist[x][y] != newDist) {
					dist[x][y] = newDist;
					dijk.push({newDist, {x, y}});
				}
			}
			for(int y = coord.second - 1; y <= coord.second + 1; y += 2) {
				int x = coord.first;
				if(y < 0 || y >= w) continue;
				if(unvisited.find({x, y}) == unvisited.end()) continue;
				int newDist;
				if(map[x][y] == '.') {
					newDist = min(dist[x][y], currDist + 1);
				} else if (map[x][y] == '#') {
					continue;
				} else {
					newDist = min(dist[x][y], currDist + 1 + d);
				}
				if(dist[x][y] != newDist) {
					dist[x][y] = newDist;
					dijk.push({newDist, {x, y}});
				}
			}
		}
	}
	
	return 0;
}