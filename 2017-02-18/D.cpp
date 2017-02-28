#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main(){
	ios::sync_with_stdio(0);
	
	ll n, m; cin >> n >> m;

	map<string, ll> langs;
	langs["English"] = n;

	for(ll i = 0; i < n; i++) {
		string curr; cin >> curr; langs[curr] = i;
	}

	map<ll, vector<pii>> graph;

	for(ll i = 0; i < m; i++) {
		string s1, s2; ll dist; cin >> s1 >> s2 >> dist;

		graph[langs[s1]].push_back({langs[s2], dist});
		graph[langs[s2]].push_back({langs[s1], dist});
	}

	queue<ll> bfsq;
	map<ll, ll> cost; cost[n] = 0;
	map<ll, ll> par;
	map<ll, ll> dist; dist[n] = 0;
	set<ll> visited; visited.insert(n);
	bfsq.push(n);

	while(!bfsq.empty()) {
		ll curr = bfsq.front(); bfsq.pop();

		for(pii next : graph[curr]) {
			if(!visited.count(next.first)) {
				visited.insert(next.first);
				par[next.first] = curr;
				cost[next.first] = next.second;
				dist[next.first] = dist[curr] + 1;
				bfsq.push(next.first);
			} else {
				if(dist[next.first] == dist[curr] + 1) {
					if(cost[next.first] > next.second) {
						par[next.first] = curr;
						cost[next.first] = next.second;
					}
				}
			}
		}
	}

	if(visited.size() < n+1) {
		cout << "Impossible" << endl;
		return 0;
	}

	map<ll, vector<ll>> newGraph;
	for(pii curr : par) {
		newGraph[curr.second].push_back(curr.first);
	}
	ll totalCost = 0;
	bfsq.push(n);
	while(!bfsq.empty()) {
		ll curr = bfsq.front(); bfsq.pop();
		for(ll next : newGraph[curr]) {
			totalCost += cost[next];
			bfsq.push(next);
		}
	}

	cout << totalCost << endl;

	return 0;
}