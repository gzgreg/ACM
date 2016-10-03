#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int bfs(int start, int end, map<int, set<int>> adj) {
	queue<int> bfsq; bfsq.push(start);
	map<int, int> dist; dist[start] = 0;
	while(!bfsq.empty()){
		int curr = bfsq.front(); bfsq.pop();
		for(int val : adj[curr]){
			if(!dist.count(val)) {
				dist[val] = dist[curr] + 1;
				if(val == end) {
					return dist[val];
				}
				bfsq.push(val);
			}
		}
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	while(T--) {
		int n, m, x, y; cin >> n >> m >> x >> y;
		map<int, set<int>> adj;

		for(int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			adj[u].insert(v);
		}
		int dist1 = bfs(x, y, adj);
		int dist2 = bfs(y, x, adj);
		if(dist1 == -1 || dist2 == -1) {
			cout << -1 << endl;
		} else {
			cout << dist1 + dist2 << endl;
		}
	}
	
	return 0;
}