#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;
	vector<int> numItems(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> numItems[i];
	}
	int m; cin >> m;
	vector<set<pii>> adj (n, set<pii>());
	for(int i = 0; i < m; i++) {
		int a, b, d; cin >> a >> b >> d;
		adj[b-1].insert({a-1, d});
		adj[a-1].insert({b-1, d});
	}
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> dijk;
	dijk.push({0, {0, numItems[0]}});
	vector<int> dist (n, 1e9);
	vector<int> items (n, 0);

	while(!dijk.empty()) {
		pair<int, pii> curr = dijk.top(); dijk.pop();
		int currDist = curr.first;
		pii node = curr.second;
		if(currDist > dist[node.first]) {
			continue;
		} else {
			dist[node.first] = currDist;
			if(items[node.first] > node.second) {
				continue;
			} else {
				items[node.first] = node.second;
			}
		}
		for(pii other : adj[node.first]) {
			dijk.push({currDist + other.second, {other.first, node.second + numItems[other.first]}});
		}
	}

	if(dist[n-1] > 1e8) {
		cout << "impossible" << endl;
	} else {
		cout << dist[n-1] << " " << items[n-1] << endl;
	}
	return 0;
}