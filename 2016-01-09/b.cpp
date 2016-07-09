#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int v, e;
	while(cin >> v){
		cin >> e;
		int coins[v + 1];
		vector<set<int> > adj;
		vector<pair<int, int> > edges;
		int max = 0;
		for(int i = 0; i < v; i++){
			cin >> coins[i + 1];
			if(coins[i + 1] > max) max = coins[i + 1];
			set<int> empty;
			adj.push_back(empty);
			adj[i].insert(i);
		}
		set<int> empty;
		adj.push_back(empty);
		adj[v].insert(v);

		for(int i = 0; i < e; i++){
			int first, second; cin >> first >> second;
			adj[first].insert(second);
			adj[second].insert(first);
			edges.push_back(make_pair(first, second));
			if(coins[first] + coins[second] > max) max = coins[first] + coins[second];
		}

		vector<set<int> > tris;

		for(int i = 0; i < e; i++){
			for(int j = 0; j < e; j++){
				if(i == j) continue;
				pair<int, int> edge1 = edges[i];
				pair<int, int> edge2 = edges[j];
				int x1 = edge1.first;
				int x2 = edge1.second;
				int y1 = edge2.first;
				int y2 = edge2.second;
				if(adj[x1].find(y1) != adj[x1].end() 
					&& adj[x2].find(y1) != adj[x2].end()
					&& adj[x1].find(y2) != adj[x1].end()
					&& adj[x2].find(y2) != adj[x2].end()){
					int tot = 0;
					set<int> tri; 
					tri.insert(x1); tri.insert(x2); tri.insert(y1); tri.insert(y2);
					for(auto it = tri.begin(); it != tri.end(); it++){
						tot += coins[*it];
					}
					if(tot > max) max = tot;
				}
			}
		}

		cout << max << endl;
	}

	return 0;
}