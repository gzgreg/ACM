#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<pair<pii, pii>, int> memo;

int bfs(vector<string> graph, pii start, pii end) {

	if(memo.count({start, end})) return memo[{start, end}];
	queue<pair<int, int>> bfsq;
	map<pii, bool> visited;
	vector<vector<int>> dist (300, vector<int> (300, 100));
	bfsq.push(start);
	dist[start.first][start.second] = 0;

	while(!bfsq.empty()) {
		pii curr = bfsq.front(); bfsq.pop();
		visited[curr] = true;
		for(int i = -1; i <= 1; i += 2) {
			pii newLoc = {curr.first + i, curr.second};
			if(newLoc.first < 0 || newLoc.first >= graph.size()) continue;
			if(graph[newLoc.first][newLoc.second] == '#') continue;
			if(visited[newLoc]) continue;

			bfsq.push(newLoc);
			visited[newLoc] = true;
			dist[newLoc.first][newLoc.second] = dist[curr.first][curr.second] + 1;
		}
		for(int i = -1; i <= 1; i += 2) {
			pii newLoc = {curr.first, curr.second + i};
			if(newLoc.second < 0 || newLoc.second >= graph[curr.first].size()) continue;
			if(graph[newLoc.first][newLoc.second] == '#') continue;
			if(visited[newLoc]) continue;

			bfsq.push(newLoc);
			visited[newLoc] = true;
			dist[newLoc.first][newLoc.second] = dist[curr.first][curr.second] + 1;
		}
		if(curr.first == end.first && curr.second == end.second) break;
	}	

	return memo[{start, end}] = dist[end.first][end.second];
}

int main(){
	ios::sync_with_stdio(0);
	
	vector<string> graph;

	string s;
	while(cin >> s) graph.push_back(s);

	vector<pii> targets;
	pii start;

	for(int i = 0; i <= 7; i++) {
		for(int j = 0; j < graph.size(); j++) {
			bool found = false;
			for(int k = 0; k < graph[j].size(); k++) {
				if(graph[j][k] - '0' == i) {
					if(i == 0) {
						start = {j, k};
					} else {
						targets.push_back({j, k});
					}
					found = true; break;
				}
			}
			if(found) break;
		}
	}

	int minSteps = 1e9;

	do {
		pii loc = start;
		int currSteps = 0;
		cout << "eifuh" << endl;
		for(int i = 0; i < targets.size(); i++) {
			currSteps += bfs(graph, loc, targets[i]);
			loc = targets[i];
		}
		currSteps += bfs(graph, loc, start);
		minSteps = min(minSteps, currSteps);
	} while(next_permutation(targets.begin(), targets.end()));

	cout << minSteps << endl;

	return 0;
}