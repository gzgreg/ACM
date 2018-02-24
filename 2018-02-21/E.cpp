#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define PI acos(-1.0)

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int J, R, D; cin >> J >> R >> D;

	vector<complex<double>> loc;
	for(int i = 0; i < J; i++) {
		double x, y; cin >> x >> y; loc.push_back({x, y});
	}
	vector<vector<int>> adj(J, vector<int>());
	for(int i = 0; i < R; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].push_back(b);
	}

	double l = 0; double r = 181;

	while(l < r - 1e-10) {
		double mid = (l + r) / 2;
		priority_queue<pair<double, pii>> dijk;
		map<pii, double> dist;
		dijk.push({0, {0, -1}});
		dist[{0, -1}] = 0;
		bool reached = false;
		while(!dijk.empty()) {
			auto curr = dijk.top(); dijk.pop();
			double currDist = curr.first;
			pii node = curr.second;
			if(node.first == J-1) {
				reached = true;
				if(currDist - 1e-8 > D) {
					l = mid;
					break;
				} else {
					r = mid;
					break;
				}
			}
			if(currDist < dist[node]) continue;
			for(int next : adj[node.first]) {
				pii nextNode = {next, node.first};
				double angle = abs(arg((loc[next] - loc[node.first]) / (loc[node.first] - loc[node.second]))) * 180 / PI;
				
				if(node.second != -1 && angle >= mid) {
					continue;
				}
				double nextDist = abs(loc[next] - loc[node.first]) + currDist;
				if(!dist.count(nextNode) || dist[nextNode] > nextDist) {
					dist[nextNode] = nextDist;
					dijk.push({nextDist, nextNode});
				}
			}
		}
		if(!reached) {
			l = mid;
		}
	}

	if(l > 180) {
		cout << "Impossible" << endl;
	} else {
		cout << fixed << setprecision(10) << l << endl;
	}
	
	return 0;
}