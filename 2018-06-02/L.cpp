#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

int n, m; 
int id(int i, int j) {
	return m*i + j;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while(T--) {
		cin >> n >> m;

		vector<vector<int>> cost (n, vector<int>(m));
		vector<vector<int>> t (n, vector<int>(m-1));

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> cost[i][j];
			}
		}

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m-1; j++) {
				cin >> t[i][j];
			}
		}

		vector<vector<int>> validCrossings;
		ll totalCost = 0;
		for(int i = 0; i < n; i++) {
			ll curMinCost = 1e9 + 1;
			for(auto cur : cost[i]) {
				curMinCost = min((ll)cur, curMinCost);
			}
			totalCost += curMinCost;
			vector<int> loc;
			for(int j = 0; j < m; j++) {
				if(cost[i][j] == curMinCost) {
					loc.push_back(j);
				}
			}
			validCrossings.push_back(loc);
		}

		vector<vector<pii>> adj ((n+1)*m);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m-1; j++) {
				adj[id(i, j)].push_back({id(i, j+1), t[i][j]});
				adj[id(i, j+1)].push_back({id(i, j), t[i][j]});
			}
			for(auto cur : validCrossings[i]) {
				adj[id(i, cur)].push_back({id(i+1, cur), 0});
			}
		}
		// for(int i = 0; i < (n+1) * m; i++) {
		// 	cout << i << " ADJ: ";
		// 	for(auto val : adj[i]) {
		// 		cout << "(" << val.first << " " << val.second << ") ";
		// 	}
		// 	cout << endl;
		// }

		auto dist = vector<ll> ((n+1)*m, 1e16);
		priority_queue<pii, vector<pii>, greater<pii>> dijk;

		dijk.push({0, 0});
		dist[0] = 0;

		while(!dijk.empty()) {
			pii curr = dijk.top(); dijk.pop();
			ll currDist = curr.first;
			ll node = curr.second;
			if(currDist > dist[node]) continue;
			for(pii next : adj[node]) {
				int nextNode = next.first;
				int nextDist = next.second;
				if(dist[nextNode] > dist[node] + nextDist) {
					dist[nextNode] = dist[node] + nextDist;
					dijk.push({dist[node] + nextDist, nextNode});
				} 
			}
		}
		ll totalTime = 1e16;
		for(int i = 0; i < m; i++) {
			totalTime = min(totalTime, dist[id(n, i)]);
		}

		cout << totalCost << " " << totalTime << endl;
	}
	
	return 0;
}