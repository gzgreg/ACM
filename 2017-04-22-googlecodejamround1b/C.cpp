#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, Q; 
vector<pair<int, ld>> bfs(int loc, pii horse, vector<set<pii>> &adj) {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> dijk;
	dijk.push({0, loc});
	vector<int> dist(N, -1);
	dist[loc] = 0;
	set<int> visited;
	while(!dijk.empty()) {
		pair<ll, int> currP = dijk.top(); dijk.pop();
		int curr = currP.second;
		if(currP.first > horse.first) break;
		if(visited.count(curr)) continue;
		visited.insert(curr);
		for(pii next : adj[curr]) {
			if(dist[next.first] == -1) {
				dist[next.first] = dist[curr] + next.second;
			} else {
				dist[next.first] = min(dist[next.first], dist[curr] + next.second);
			}
			
			dijk.push({dist[next.first], next.first});
		}
	}
	vector<pair<int, ld>> ans;
	for(int i = 0; i < N; i++) {
		if(dist[i] != -1 && dist[i] <= horse.first && i != loc) {
			ans.push_back({i, (ld) dist[i] / horse.second});
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	for(int id = 1; id <= T; id++) {
		cin >> N >> Q;
		vector<pii> horses;
		for(int i = 0; i < N; i++) {
			int Ei, Si; cin >> Ei >> Si; horses.push_back({Ei, Si});
		}
		vector<set<pii>> adj (N, set<pii>());

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				int curr; cin >> curr;
				if(curr != -1) {
					adj[i].insert({j, curr});
				}
			}
		}
		cout << "Case #" << id << ": ";
		for(int i = 0; i < Q; i++) {
			int Ui, Vi; cin >> Ui >> Vi;
			Ui--; Vi--;

			priority_queue<pair<long double, int>, vector<pair<long double, int>>, greater<pair<long double, int>>> dijk;
			ld dist[N+1];
			for(long long j = 0; j < N; j++){
				dist[j] = -1;
			}
			dijk.push(make_pair(0, Ui));
			dist[Ui] = 0;
			while(!dijk.empty()){
				pair<long double, int> curr = dijk.top(); dijk.pop();
				long double currDist = curr.first;
				int loc = curr.second;
				if(loc == Vi) break;
				auto edges = bfs(loc, horses[loc], adj);
				for(pair<int, ld> next : edges){
					ld newDist = currDist + next.second;
					if(dist[next.first] == -1 || dist[next.first] > newDist){
						
						dijk.push(make_pair(newDist, next.first));
						dist[next.first] = newDist;
					}
				}
			}
			cout << fixed << setprecision(10) << dist[Vi] << " ";
		}
		cout << endl;

	}
	
	return 0;
}