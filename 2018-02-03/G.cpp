#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M; cin >> N >> M;
	vector<vector<int>> adj(N, vector<int>());

	for(int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int K; cin >> K;
	vector<int> liked;
	for(int i = 0; i < K; i++) {
		int cur; cin >> cur; cur--; liked.push_back(cur);
	}
	queue<int> bfsq;
	for(auto cur : liked) {
		bfsq.push(cur);
	}
	vector<bool> vis(N, false);
	for(auto cur : liked) {
		vis[cur] = true;
	}
	vector<int> dist(N, -1);
	for(auto cur : liked) {
		dist[cur] = 0;
	}

	while(!bfsq.empty()) {
		int curr = bfsq.front(); bfsq.pop();
		for(int next : adj[curr]) {
			if(vis[next]) continue;
			vis[next] = true;
			dist[next] = dist[curr] + 1;
			bfsq.push(next);
		}
	}

	for (auto cur : dist) {
		cout << cur << " " ;
	}
	cout << endl;
	
	return 0;
}