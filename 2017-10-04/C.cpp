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

	int n; cin >> n;

	vector<vector<pii>> adj  = vector<vector<pii>> (n);
	vector<int> dist (n, 1e9);
	map<int, int> numItems;

	for(int i = 0; i < n; i++) {
		int t; cin >> t; numItems[i] = t;
	}

	int m; cin >> m;

	for(int i = 0; i < m; i++) {
		int p1, p2, l; cin >> p1 >> p2 >> l;
		p1--; p2--;
		adj[p1].push_back({l, p2});
		adj[p2].push_back({l, p1});
	}

	priority_queue<pii, vector<pii>, greater<pii>> dijk;
	dijk.push({0, 0});
	dist[0] = 0;

	map<int, int> items;
	items[0] = numItems[0];

	while(!dijk.empty()) {
		pii curr = dijk.top(); dijk.pop();
		int currDist = curr.first;
		int node = curr.second;
		if(currDist > dist[node]) continue;
		for(pii next : adj[node]) {
			int nextNode = next.second;
			int nextDist = next.first;
			if(dist[nextNode] > dist[node] + nextDist) {
				dist[nextNode] = dist[node] + nextDist;
				dijk.push({dist[node] + nextDist, nextNode});
				items[nextNode] = items[node] + numItems[nextNode];
			} else if(dist[nextNode] == dist[node] + nextDist) {
				items[nextNode] = max(items[nextNode], items[node] + numItems[nextNode]);
			}
		}
	}
	if(dist[n-1] == 1e9) {
		cout << "impossible" << endl;
	} else {

		cout << dist[n-1] << " " << items[n-1] << endl;
	}
	
	return 0;
}