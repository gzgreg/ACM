#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	
	int n, m, k; cin >> n >> m >> k;

	vector<int> iron, coal;

	for(int i = 0; i < m; i++) {
		int curr; cin >> curr; iron.push_back(curr - 1);
	}

	for(int i = 0; i < k; i++) {
		int curr; cin >> curr; coal.push_back(curr - 1);
	}

	vector<vector<int>> graph(n, vector<int>()), revGraph(n, vector<int>());

	for(int i = 0; i < n; i++) {
		int a; cin >> a;
		for(int j = 0; j < a; j++) {
			int curr; cin >> curr;
			graph[i].push_back(curr - 1);
			revGraph[curr - 1].push_back(i);
		}
	}

	map<int, int> dist1, dist2, dist3;

	dist1[0] = 0;
	queue<int> bfsq;
	bfsq.push(0);
	set<int> visited; visited.insert(0);
	while(!bfsq.empty()) {
		int curr = bfsq.front(); bfsq.pop();
		for(int next : graph[curr]) {
			if(!visited.count(next)) {
				visited.insert(next);
				dist1[next] = dist1[curr] + 1;
				bfsq.push(next);
			}
		}
	}

	visited.clear();

	for(int i : iron) {
		dist2[i] = 0;
		visited.insert(i);
		bfsq.push(i);
	}
	while(!bfsq.empty()) {
		int curr = bfsq.front(); bfsq.pop();
		for(int next : revGraph[curr]) {
			if(!visited.count(next)) {
				visited.insert(next);
				dist2[next] = dist2[curr] + 1;
				bfsq.push(next);
			}
		}
	}
	visited.clear();
	for(int i : coal) {
		dist3[i] = 0;
		visited.insert(i);
		bfsq.push(i);
	}
	while(!bfsq.empty()) {
		int curr = bfsq.front(); bfsq.pop();
		for(int next : revGraph[curr]) {
			if(!visited.count(next)) {
				visited.insert(next);
				dist3[next] = dist3[curr] + 1;
				bfsq.push(next);
			}
		}
	}

	int bestNum = 1e7;

	for(int i = 0; i < n; i++) {
		if(!dist1.count(i) || !dist2.count(i) || !dist3.count(i)) {
			continue;
		} else {
			bestNum = min(bestNum, dist1[i] + dist2[i] + dist3[i]);
		}
	}

	if(bestNum == 1e7) {
		cout << "impossible" << endl;
	} else {
		cout << bestNum << endl;
	}

	return 0;
}