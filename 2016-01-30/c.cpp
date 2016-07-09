#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	long long N, M; cin >> N >> M;

	vector<pair<long long, pair<long long, long long>>> places;

	for(long long i = 0; i < N; i++){
		long long z, x, y; cin >> z >> x >> y;
		places.push_back(make_pair(z, make_pair(x, y)));
	}

	double adj[N+1][N+1]; memset(adj, 0, sizeof adj);

	for(long long i = 0; i < M; i++){
		long long pl1, pl2;
		string type;
		cin >> pl1 >> pl2 >> type;
		if(type.compare("lift") == 0){
			adj[pl1][pl2] = 1;
			adj[pl2][pl1] = 1;
		} else if(type.compare("stairs") == 0 || type.compare("walking") == 0){
			long long zdist = (places[pl1].first - places[pl2].first) * 5;
			long long xdist = places[pl1].second.first - places[pl2].second.first;
			long long ydist = places[pl1].second.second - places[pl2].second.second;
			long long dist = zdist*zdist + xdist*xdist + ydist*ydist;
			adj[pl1][pl2] = sqrt(dist);
			adj[pl2][pl1] = sqrt(dist);
		} else {
			long long zdist = (places[pl1].first - places[pl2].first) * 5;
			long long xdist = places[pl1].second.first - places[pl2].second.first;
			long long ydist = places[pl1].second.second - places[pl2].second.second;
			long long dist = zdist*zdist + xdist*xdist + ydist*ydist;
			adj[pl1][pl2] = 1;
			adj[pl2][pl1] = sqrt(dist*9);
		}
	}
	long long Q; cin >> Q;
	for(long long i = 0; i < Q; i++){
		long long a, b; cin >> a >> b;
		set<long long> visited;
		vector<long long> parent (N+1, -1);
		priority_queue<pair<double, long long>, vector<pair<double, long long>>, greater<pair<double, long long>>> dijk;
		double dist[N+1];
		for(long long j = 0; j < N; j++){
			dist[j] = -1;
		}

		dijk.push(make_pair(0, a));
		dist[a] = 0;
		parent[a] = a;
		while(!dijk.empty()){
			pair<double, long long> curr = dijk.top(); dijk.pop();
			double currDist = curr.first;
			long long loc = curr.second;
			if(loc == b) break;
			for(long long j = 0; j < N; j++){
				if(j == loc) continue;
				double newDist = currDist + adj[loc][j];
				if(abs(adj[loc][j]) > 0.01 && (dist[j] > newDist || abs(dist[j]+1) < 0.01) && visited.find(loc) == visited.end()){
					dijk.push(make_pair(newDist, j));
					dist[j] = newDist;
					parent[j] = loc;
				}
			}
			visited.insert(loc);
		}

		long long currLoc = b;
		stack<long long> route;
		while(currLoc != a){
			route.push(currLoc);
			currLoc = parent[currLoc];
		}

		route.push(a);
		while(!route.empty()){
			cout << route.top() << " ";
			route.pop();
		}
		cout << endl;

	}

	return 0;
}