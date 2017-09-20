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

	int n; cin >> n;

	vector<vector<int>> adj(n, vector<int>(n, 0));
	vector<pair<int, pii>> dists;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> adj[i][j];
			if(adj[i][j] != 0) {
				dists.push_back({adj[i][j], {i, j}});
			}
		}
	}

	sort(dists.begin(), dists.end());

	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(adj[i][j] > adj[i][k] + adj[k][j]) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}