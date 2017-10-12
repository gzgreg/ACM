#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n, m, f, s, t; cin >> n >> m >> f >> s >> t;

	vector<vector<pii>> adjR(n, vector<pii>());
	vector<vector<ll>> adjF(n, vector<ll>());

	for(ll i = 0; i < m; i++) {
		ll ii, j, c; cin >> ii >> j >> c;
		adjR[ii].push_back({j, c});
		adjR[j].push_back({ii, c});
	}

	for(ll i = 0; i < f; i++) {
		ll u, v; cin >> u >> v;
		adjF[u].push_back(v);
	}

	priority_queue<pair<ll, pair<ll, bool>>, 
		vector<pair<ll, pair<ll, bool>>>,
		greater<pair<ll, pair<ll, bool>>>> dijk;

	map<pair<ll, bool>, ll> dist;
	dijk.push({0, {s, true}});
	dist[{s, true}] = 0;

	while(!dijk.empty()) {
		auto curr = dijk.top(); dijk.pop();
		ll currDist = curr.first;
		auto node = curr.second;
		if(currDist > dist[node]) continue;
		for(pii next : adjR[node.first]) {
			ll nextNode = next.first;
			ll nextDist = next.second;
			if(!dist.count({nextNode, node.second})
				|| dist[{nextNode, node.second}] > dist[node] + nextDist) {
				dist[{nextNode, node.second}] = dist[node] + nextDist;
				dijk.push({dist[node] + nextDist, {nextNode, node.second}});
			}
		}
		if(!node.second) continue;
		for(ll next : adjF[node.first]) {
			if(!dist.count({next, false})
				|| dist[{next, false}] > dist[node]) {
				dist[{next, false}] = dist[node];
				dijk.push({dist[node], {next, false}});
			}
		}
	}
	ll minAns = 1e18;
	if(dist.count({t, true})) {
		minAns = min(minAns, dist[{t, true}]);
	}

	if(dist.count({t, false})) {
		minAns = min(minAns, dist[{t, false}]);
	}
	cout << minAns << endl;

	return 0;
}