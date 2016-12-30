#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	vector<vector<bool>> graph (60, vector<bool>(60, false));

	for(int i = 0; i < 60; i++) {
		for(int j = 0; j < 60; j++) {
			unsigned int num = i*i + 3*i + 2*i*j + j + j*j;
			num += 1362;

			if(__builtin_popcount (num) % 2) {
				graph[i][j] = true;
			}
		}
	}

	queue<pair<int, int>> bfsq;
	map<pii, bool> visited;
	vector<vector<int>> dist (60, vector<int> (60, 100));
	bfsq.push({1, 1});
	dist[1][1] = 0;

	while(!bfsq.empty()) {
		pii curr = bfsq.front(); bfsq.pop();		visited[curr] = true;
		for(int i = -1; i <= 1; i += 2) {
			pii newLoc = {curr.first + i, curr.second};
			if(newLoc.first < 0 || newLoc.first >= 60) continue;
			if(graph[newLoc.first][newLoc.second]) continue;
			if(visited[newLoc]) continue;

			bfsq.push(newLoc);
			visited[newLoc] = true;
			dist[newLoc.first][newLoc.second] = dist[curr.first][curr.second] + 1;
		}
		for(int i = -1; i <= 1; i += 2) {
			pii newLoc = {curr.first, curr.second + i};
			if(newLoc.second < 0 || newLoc.second >= 60) continue;
			if(graph[newLoc.first][newLoc.second]) continue;
			if(visited[newLoc]) continue;

			bfsq.push(newLoc);
			visited[newLoc] = true;
			dist[newLoc.first][newLoc.second] = dist[curr.first][curr.second] + 1;
		}
	}	
	int tot = 0;

	for(int i = 0; i < 60; i++) {
		for(int j = 0; j < 60; j++) {
			if(dist[i][j] <= 50) tot++;
		}
		cout << endl;
	}
	cout << tot;
	
	return 0;
}