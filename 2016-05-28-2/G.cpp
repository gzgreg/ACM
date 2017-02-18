#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int W, H; cin >> W >> H;

	vector<string> graph;

	for(int i = 0; i < H; i++) {
		string curr; cin >> curr; graph.push_back(curr);
	}
	pii start;
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			if(graph[i][j] == 'P') {
				start = {i, j};
				break;
			}
		}
	}

	queue<pii> bfsq; bfsq.push(start);
	int gold = 0;
	set<pii> visited;
	while(!bfsq.empty()) {
		pii curr = bfsq.front(); bfsq.pop();

		if(graph[curr.first][curr.second] == 'G') {
			gold++;
		}

		vector<pii> locs = {{curr.first + 1, curr.second},
							{curr.first - 1, curr.second},
							{curr.first, curr.second + 1},
							{curr.first, curr.second - 1}};
		bool trapped = false;
		for(pii loc : locs) {
			if(graph[loc.first][loc.second] == 'T') {
				trapped = true;
				break;
			}
		}
		if(trapped) continue;
		for(pii loc : locs) {
			if(loc.first < 0 || loc.first >= H
				|| loc.second < 0 || loc.second >= W
				|| visited.count(loc)
				|| graph[loc.first][loc.second] == '#'){
				continue;
			}

			bfsq.push(loc);
			visited.insert(loc);
		}
	}

	cout << gold << endl;
	
	return 0;
}