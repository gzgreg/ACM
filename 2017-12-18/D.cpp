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

	int N, M, K; cin >> N >> M >> K;

	vector<vector<int>> adj(N);
	for(int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}

	for(int i = 0; i < N; i++) {
		queue<int> bfsq;
		bfsq.push(i);
		vector<int> dist(N, -1);
		dist[i] = 0;
		while(!bfsq.empty()) {
			int curr = bfsq.front(); bfsq.pop();
			for(int next : adj[curr]) {
				if(dist[next] != -1) continue;
				dist[next] = dist[curr] + 1;
				bfsq.push(next);
			}
		}

		int maxDist = 0;
		for(auto cur : dist) {
			maxDist = max(maxDist, cur);
		}
		if(maxDist > N-K) {
			cout << 0 << endl;
			return 0;
		}
	}
	cout << N << endl;
	for(int i = 0; i < N; i++) {
		cout << i+1 << " ";
	}
	cout << endl;
	
	return 0;
}