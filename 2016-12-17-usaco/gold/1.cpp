#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pii> locs;
int N; 

bool solve(int pow) {
	vector<vector<int>> adj (N, vector<int>());
	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			int dx = locs[i].first - locs[j].first;
			int dy = locs[i].second - locs[j].second;
			int sqrdist = dx*dx + dy*dy;
			if(sqrdist <= pow) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	queue<int> bfsq; bfsq.push(0);
	set<int> visited;
	while(!bfsq.empty()){
		int curr = bfsq.front(); bfsq.pop();
		for(int val : adj[curr]){
			if(!visited.count(val)) {
				visited.insert(val);
				bfsq.push(val);
			}
		}
	}
	return visited.size() == N;
}

int find() {
	int l = 0, r = 1250000000;

	while(l <= r) {
		int mid = l + (r - l) / 2;
		if(solve(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return l;
}

int main(){
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);

	cin >> N;
	
	for(int i = 0; i < N; i++) {
		int a, b; cin >> a >> b; locs.push_back({a, b});
	}

	cout << find() << endl;

	return 0;
}