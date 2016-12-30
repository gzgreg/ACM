#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);

	int N; cin >> N;
	vector<pii> locs;
	vector<int> pows;
	for(int i = 0; i < N; i++) {
		int a, b; cin >> a >> b; locs.push_back({a, b});
		int pow; cin >> pow; pows.push_back(pow);
	}

	vector<vector<int>> adj (N, vector<int>());
	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			int dx = locs[i].first - locs[j].first;
			int dy = locs[i].second - locs[j].second;
			double dist = sqrt(dx*dx + dy*dy);
			if((dist - pows[i]) < 1e-7) {
				adj[i].push_back(j);
			}

			if((dist - pows[j]) < 1e-7) {
				adj[j].push_back(i);
			}
		}
	}
	int maxNum = 0;
	for(int i = 0; i < N; i++) {
		queue<int> bfsq; bfsq.push(i);
		set<int> visited;
		while(!bfsq.empty()){
			int curr = bfsq.front(); bfsq.pop();
			visited.insert(curr);
			for(int val : adj[curr]){
				if(!visited.count(val)) {
					bfsq.push(val);
				}
			}
		}
		int num = visited.size();
		maxNum = max(maxNum, num);
	}
	cout << maxNum << endl;

	return 0;
}