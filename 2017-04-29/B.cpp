#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int P, T;
vector<int> vis;
vector<vector<pii>> adj;
vector<int> dist;
pair<bool, int> dfs(int node) {
	if(node == P-1) return {true, 0};
	int ans = 0;
	bool ans2 = false;
	for(pii next : adj[node]) {
		if(dist[next.second] == dist[node] + next.first) {
			if(!vis[next.second]){
				pair<bool, int> currAns = dfs(next.second);
				// cout << currAns.first << " " << currAns.second << endl;
				if(currAns.first) {
					ans2 = true;
					ans += currAns.second;
					ans += next.first;
					vis[next.second] = 2;
				} else {
					vis[next.second] = 1;
				}
			} else {
				if(vis[next.second] == 2) {
					ans2 = true;
					ans += next.first;
				}
			}			
		}
	}
	return {ans2, ans};
}

int main(){
	ios::sync_with_stdio(0);
	cin >> P >> T;
	adj  = vector<vector<pii>> (P, vector<pii>());
	dist = vector<int> (P, 1e9);
	vis = vector<int>(P, 0);
	priority_queue<pii, vector<pii>, greater<pii>> dijk;
	for(int i = 0; i < T; i++) {
		int p1, p2, l; cin >> p1 >> p2 >> l;

		adj[p1].push_back({l, p2});
		adj[p2].push_back({l, p1});
	}

	for(int i = 0; i < P; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	dijk.push({0, 0});
	dist[0] = 0;

	int minDist = 1e9;
	int totDist = 0;

	while(!dijk.empty()) {
		pii curr = dijk.top(); dijk.pop();
		int currDist = curr.first;
		int node = curr.second;
		if(node == P-1) break;
		if(currDist > dist[node]) continue;
		for(pii next : adj[node]) {
			int nextNode = next.second;
			int nextDist = next.first;
			if(dist[nextNode] > dist[node] + nextDist) {
				dist[nextNode] = dist[node] + nextDist;
				dijk.push({dist[node] + nextDist, nextNode});
			}
		}
	}

	cout << 2*dfs(0).second << endl;
	return 0;
}