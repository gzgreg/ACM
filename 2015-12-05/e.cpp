#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int n, m; 
	while(cin >> n){
		if(n == 0)break;
		vector<vector<pair<int, int> > > adj;
		map<int, double> prob;
		cin >> m;
		for(int i = 0; i < n; i++){
			vector<pair<int, int> > empty;
			adj.push_back(empty);
			prob[i] = 0;
		}
		for(int i = 0; i < m; i++){
			int a, b, p; cin >> a >> b >> p;
			adj[a-1].push_back(make_pair(b-1, p));
			adj[b-1].push_back(make_pair(a-1, p));
		}

		set<int> visited;
		visited.insert(0);
		prob[0] = 100;
		int curr = 0;
		while(curr != n-1){
			vector<pair<int, int> > conn = adj[curr];
			visited.insert(curr);
			for(int i = 0; i < conn.size(); i++){
				int city = conn[i].first;
				int pct = conn[i].second;
				if(visited.find(city) != visited.end()){
					continue;
				}
				if(prob[city] < (double)prob[curr] * pct / 100){
					prob[city] = (double)prob[curr] * pct / 100;
				}
			}
			int maxCity;
			double maxVal = 0;
			for(int i = 0; i < n; i++){
				if(visited.find(i) != visited.end()) continue;
				if(prob[i] > maxVal){
					maxVal = prob[i];
					maxCity = i;
				}
			}
			curr = maxCity;
		}

		cout << fixed << setprecision(6) << prob[n-1] << " percent" << endl;
	}
	return 0;
}