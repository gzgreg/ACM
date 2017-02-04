#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int N; cin >> N;
	vector<string> graph;

	for(int i = 0; i < N; i++) {
		string s; cin >> s; graph.push_back(s);
	}
	reverse(graph.begin(), graph.end());

	queue<vi> bfsq;
	map<vi, bool> visited;
	map<vi, int> dist;
	bfsq.push({0, 0, 0, 0, 0});
	dist[{0, 0, 0, 0, 0}] = 0;

	while(!bfsq.empty()) {
		vi curr = bfsq.front(); bfsq.pop();
		if(curr[0] == N-1
			&& curr[1] == N-1
			&& curr[3] == N-1
			&& curr[4] == N-1) {
			cout << dist[curr] << endl;
			return 0;
		}
		vi newVec(curr);

		newVec[2] = (newVec[2] + 1) % 4;
		if(!visited[newVec]) {
			bfsq.push(newVec);
			visited[newVec] = true;
			dist[newVec] = dist[curr] + 1;
		}

		newVec = vi(curr);
		newVec[2] = (newVec[2] + 3) % 4;
		if(!visited[newVec]) {
			bfsq.push(newVec);
			visited[newVec] = true;
			dist[newVec] = dist[curr] + 1;
		}

		newVec = vi(curr);
		if(curr[0] != N-1 || curr[1] != N-1) {
			switch(curr[2]) {
				case 0: {
					if(newVec[0] + 1 < N
						&& graph[newVec[0] + 1][newVec[1]] == 'E') {
						newVec[0]++;
					}
					break;
				}
				case 1: {
					if(newVec[1] + 1 < N
						&& graph[newVec[0]][newVec[1] + 1] == 'E') {
						newVec[1]++;
					}
					break;
				}
				case 2: {
					if(newVec[0] - 1 >= 0
						&& graph[newVec[0] - 1][newVec[1]] == 'E') {
						newVec[0]--;
					}
					break;
				}
				case 3: {
					if(newVec[1] - 1 >= 0
						&& graph[newVec[0]][newVec[1] - 1] == 'E') {
						newVec[1]--;
					}
					break;
				}
			}
		}
		if(curr[3] != N-1 || curr[4] != N-1) {
			switch((curr[2] + 1) % 4) {
				case 0: {
					if(newVec[3] + 1 < N
						&& graph[newVec[3] + 1][newVec[4]] == 'E') {
						newVec[3]++;
					}
					break;
				}
				case 1: {
					if(newVec[4] + 1 < N
						&& graph[newVec[3]][newVec[4] + 1] == 'E') {
						newVec[4]++;
					}
					break;
				}
				case 2: {
					if(newVec[3] - 1 >= 0
						&& graph[newVec[3] - 1][newVec[4]] == 'E') {
						newVec[3]--;
					}
					break;
				}
				case 3: {
					if(newVec[3] - 1 >= 0
						&& graph[newVec[3]][newVec[4] - 1] == 'E') {
						newVec[4]--;
					}
					break;
				}
			}
		}

		if(!visited[newVec]) {
			bfsq.push(newVec);
			visited[newVec] = true;
			dist[newVec] = dist[curr] + 1;
		}
	}	

	
	return 0;
}