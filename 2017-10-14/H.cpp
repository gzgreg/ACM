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

	int N, M, R; cin >> N >> M >> R;
	vector<set<pii>> cars(N);

	int n1, l1, d1; cin >> n1 >> l1 >> d1;

	for(int i = 1; i < M; i++) {
		int n, l, d; cin >> n >> l >> d;

		cars[n].insert({d, d + l});
	}

	vector<set<pii>> gaps(N);
	for(int i = 0; i < N; i++) {
		if(cars[i].size() > 0) {
			gaps[i].insert({0, (*cars[i].begin()).first});
			auto it = cars[i].begin();
			auto it2 = it;
			it2++;
			for(; it2 != cars[i].end(); it++, it2++) {
				gaps[i].insert({(*it).second, (*it2).first});
			}
			gaps[i].insert({(*(--cars[i].end())).second, R});
		} else {
			gaps[i].insert({0, R});
		}
	}

	map<pii, int> idxMap;
	int intervalId = 0;
	int firstGapInEnd = -1;
	for(int i = 0; i < N; i++) {
		if(i == N-1 && firstGapInEnd == -1) {
			firstGapInEnd = intervalId;
		}
		for(pii cur : gaps[i]) {
			idxMap[{i, cur.first}] = intervalId;
			intervalId++;
		}
	}

	vector<vector<pii>> adj(intervalId);
	for(int i = 0; i < N-1; i++) {
		auto ji = gaps[i].begin();
		for(int j = 0; j < gaps[i].size(); j++, ji++) {
			auto ki = gaps[i+1].begin();
			for(int k = 0; k < gaps[i+1].size(); k++, ki++) {
				int left = max((*ji).first, (*ki).first);
				int right = min((*ji).second, (*ki).second);
				if(right >= left + l1) {
					int id1 = idxMap[{i, (*ji).first}];
					int id2 = idxMap[{i+1, (*ki).first}];
					
					adj[id1].push_back({right - left - l1, id2});
					adj[id2].push_back({right - left - l1, id1});
				}
			}
		}
	}
	int startId;
	int bestDist;
	for(pii cur : gaps[0]) {
		if(d1 >= cur.first && d1 + l1 <= cur.second) {
			startId = idxMap[{0, cur.first}];
			bestDist = d1 - cur.first;
			bestDist = min(bestDist, cur.second - d1 - l1);
			break;
		}
	}

	auto dist = vector<int> (intervalId, -1);
	priority_queue<pii> dijk;

	dijk.push({bestDist*2, startId});
	dist[startId] = bestDist*2;
	while(!dijk.empty()) {
		pii curr = dijk.top(); dijk.pop();
		int currDist = curr.first;
		int node = curr.second;
		if(node >= firstGapInEnd) continue;
		if(currDist < dist[node]) continue;
		for(pii next : adj[node]) {
			int nextNode = next.second;
			int nextDist = next.first;
			if(dist[nextNode] < min(dist[node], nextDist)) {
				dist[nextNode] = min(dist[node], nextDist);
				dijk.push({min(dist[node], nextDist), nextNode});
			}
		}
	}
	int bestAns = -1;
	for(int i = firstGapInEnd; i < intervalId; i++) {
		bestAns = max(bestAns, dist[i]);
	}
	if(bestAns != -1) {
		cout << fixed << setprecision(10) << bestAns / 2.0 << endl;
	} else {
		cout << "Impossible" << endl;
	}
	
	return 0;
}