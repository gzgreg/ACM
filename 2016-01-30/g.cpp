#include <bits/stdc++.h>

using namespace std;

bool dfs(int node, int color[], set<int> adj[]){
	if(color[node] != 0) return true;
	set<int> colors;
	for(int i = 1; i <= 4; i++){
		colors.insert(i);
	}
	for(auto it = adj[node].begin(); it != adj[node].end(); it++){
		if(color[*it] != 0) colors.erase(color[*it]);
	}
	bool ret = false;
	for(auto it = colors.begin(); it != colors.end(); it++){
		color[node] = *it;
		bool success = true;
		for(auto it2 = adj[node].begin(); it2 != adj[node].end(); it2++){
			if(!dfs(*it2, color, adj)){
				success = false;
				break;
			}
		}
		if(success){
			ret = true;
			break;
		} 
	}
	if(!ret) color[node] = 0;
	return ret;
}

int main(){
	ios::sync_with_stdio(0);

	int N; cin >> N;

	set<int> adj[N+2];
	int color[N+2];
	memset(color, 0, sizeof color);
	for(int i = 1; i <= N; i++){
		set<int> empty;
		adj[i] = empty;
	}

	string s;
	while(cin >> s){
		int idx = s.find('-');

		int first; istringstream(s.substr(0, idx)) >> first;
		int second; istringstream(s.substr(idx + 1)) >> second;

		adj[first].insert(second);
		adj[second].insert(first);
	}

	dfs(1, color, adj);

	for(int i = 1; i <= N; i++){
		cout << i << " " << color[i] << endl;
	}

	return 0;
}