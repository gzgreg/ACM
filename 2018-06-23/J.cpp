#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct passage {
	int target;
	int time;
	int security;
};

int n, m;

int distance(map<int, vector<passage>>& adj, int secLevel) {
	auto dist = vector<ll> (n, 2e9);
	priority_queue<pii, vector<pii>, greater<pii>> dijk;

	dijk.push({0, 0});
	dist[0] = 0;

	while(!dijk.empty()) {
		pii curr = dijk.top(); dijk.pop();
		ll currDist = curr.first;
		int node = curr.second;
		if(currDist > dist[node]) continue;
		for(passage next : adj[node]) {
			if(next.security > secLevel) continue;
			int nextNode = next.target;
			int nextDist = next.time;
			if(dist[nextNode] > dist[node] + nextDist) {
				dist[nextNode] = dist[node] + nextDist;
				dijk.push({dist[node] + nextDist, nextNode});
			} 
		}
	}
	return dist[n-1];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m;

	map<int, vector<passage>> adj;

	for(int i = 0; i < m; i++) {
		int xi, yi, di, si; cin >> xi >> yi >> di >> si;
		xi--; yi--;

		adj[xi].push_back({yi, di, si});
		adj[yi].push_back({xi, di, si});
	}

	int T; cin >> T;

	int l = 1, r = 1000001;

	while(l < r) {
		int mid = (l + r) / 2;
		if(distance(adj, mid) <= T) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	int ans = distance(adj, l);
	int ansSec = l-2;
	for(int i = l-2; i <= l+2; i++) {
		ans = distance(adj, i);
		ansSec = i;
		if(ans <= T) break;
	}
	if(ans > T) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		cout << ansSec << " " << distance(adj, ansSec) << endl;
	}
	
	return 0;
}