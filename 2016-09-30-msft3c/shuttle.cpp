#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	int T; cin >> T;
	for(int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";

		string start, end; cin >> start >> end;

		int n; cin >> n;

		map<string, map<string, int>> adj;
		for(int j = 0; j < n; j++) {
			string a, b; cin >> a >> b;
			int time; cin >> time;
			adj[a][b] = time;
			adj[b][a] = time;
		}

		int shuttle; cin >> shuttle;

		priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> dijk;
		dijk.push({0, start});
		map<string, int> dist;

		while(!dijk.empty()) {
			pair<int, string> curr = dijk.top(); dijk.pop();
			int currDist = curr.first;
			string node = curr.second;
			dist[node] = curr.first;
			if(node == end) {
				break;
			} 
			for(pair<string, int> other : adj[node]) {
				if(dist.count(other.first) != 0 && dist[other.first] <= currDist + other.second) continue;
				dijk.push({currDist + other.second, other.first});
			}
		}
		int outTime = dist[end];
		if(outTime < shuttle) {
			cout << outTime << " " << "Walk" << endl;
		} else {
			cout << shuttle << " Shuttle" << endl;
		}
	}
	
	return 0;
}