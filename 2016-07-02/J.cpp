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
		vector<int> lab;
		int n, m; cin >> n >> m;
		vector<set<int>> adjOrig (n, set<int>());
		vector<int> inEdgesOrig (n, 0);

		for(int i = 0; i < n; i++) {
			int curr; cin >> curr; lab.push_back(curr);
		}

		set<int> leaf;
		for(int i = 0; i < n; i++) {
			leaf.insert(i);
		}

		for(int i = 0; i < m; i++) {
			int stage1, stage2; cin >> stage1 >> stage2;
			adjOrig[stage1-1].insert(stage2-1);
			leaf.erase(stage2-1);
			inEdgesOrig[stage2 - 1]++;
		}

		queue<int> q1, q2;
		for(int currLeaf : leaf) {
			if(lab[currLeaf] == 1) {
				q1.push(currLeaf);
			} else {
				q2.push(currLeaf);
			}
		}

		int currLab = 1;
		map<int, bool> visited;
		int numSwitches;
		int currSwitches = 0;
		vector<set<int>> adj = vector<set<int>> (adjOrig);
		vector<int> inEdges = inEdgesOrig;
		while(!q1.empty() || !q2.empty()) {
			if(currLab == 1) {
				while(!q1.empty()) {
					int curr = q1.front(); q1.pop();
					if(visited[curr]) continue; visited[curr] = true;
					for(int conn : adj[curr]) {
						inEdges[conn]--;
						if(inEdges[conn] == 0) {
							lab[conn] == 1 ? q1.push(conn) : q2.push(conn);
						}
					}
				}
				currLab = 2;
				currSwitches++;
			} else {
				while(!q2.empty()) {
					int curr = q2.front(); q2.pop();
					if(visited[curr]) continue; visited[curr] = true;
					for(int conn : adj[curr]) {
						inEdges[conn]--;
						if(inEdges[conn] == 0) {
							lab[conn] == 1 ? q1.push(conn) : q2.push(conn);
						}
					}
				}
				currLab = 1;
				currSwitches++;
			}
		}
		numSwitches = currSwitches - 1;
		currLab = 2;
		visited.clear();
		currSwitches = 0;
		adj = adjOrig;
		inEdges = inEdgesOrig;
		for(int currLeaf : leaf) {
			if(lab[currLeaf] == 1) {
				q1.push(currLeaf);
			} else {
				q2.push(currLeaf);
			}
		}

		while(!q1.empty() || !q2.empty()) {
			if(currLab == 1) {
				while(!q1.empty()) {
					int curr = q1.front(); q1.pop();
					if(visited[curr]) continue; visited[curr] = true;
					for(int conn : adj[curr]) {
						inEdges[conn]--;
						if(inEdges[conn] == 0) {
							lab[conn] == 1 ? q1.push(conn) : q2.push(conn);
						}
					}
				}
				currLab = 2;
				currSwitches++;
			} else {
				while(!q2.empty()) {
					int curr = q2.front(); q2.pop();
					if(visited[curr]) continue; visited[curr] = true;
					for(int conn : adj[curr]) {
						inEdges[conn]--;
						if(inEdges[conn] == 0) {
							lab[conn] == 1 ? q1.push(conn) : q2.push(conn);
						}
					}
				}
				currLab = 1;
				currSwitches++;
			}
		}

		numSwitches = min(numSwitches, currSwitches - 1);
		cout << numSwitches << endl;
	}
	
	return 0;
}