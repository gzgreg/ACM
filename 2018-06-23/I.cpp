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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;
	vector<vector<int>> adj(n);
	vector<int> deg(n);
	for(int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		deg[a]++;
		deg[b]++;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	set<int> covered;
	vector<bool> isCovered(n);
	while(covered.size() < n) {
		if((int)covered.size() >= n-2) {
			for(int i = 0; i < n; i++) {
				if(!covered.count(i)) {
					isCovered[i] = true;
					covered.insert(i);
					break;
				}
			}
			covered.insert(n+1);
		}
		// for(auto cur : covered) {
		// 	cout << cur << " ";
		// }
		// cout << endl;
		vector<int> toRemove;
		for(int i = 0; i < n; i++) {
			if(covered.count(i)) continue;
			if(deg[j] == 1)
			for(int j : adj[i]) {
				if(covered.count(j)) continue;
				if(deg[j] == 1) {
					toRemove.push_back(i);
					break;
				}
			}
		}

		for(auto cur : toRemove) {
			for(auto node : adj[cur]) {
				for(auto neighbour : adj[node]) {
					deg[neighbour]--;
				}
				covered.insert(node);
				deg[node]--;
			}
			covered.insert(cur);
			isCovered[cur] = true;
		}
	}

	for(auto val : isCovered) cout << val << " ";
	cout << endl;
	
	return 0;
}