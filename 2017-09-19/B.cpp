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

	vector<vector<int>> adj(n, vector<int>());

	for(int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	set<int> s1, s2;
	s1.insert(0);
	queue<int> bfsq;
	bfsq.push(0);
	set<int> vis; vis.insert(0);
	while(!bfsq.empty()) {
		int curr = bfsq.front(); bfsq.pop();
		for(int next : adj[curr]) {
			if(vis.count(next)) continue;
			if(s1.count(curr)) {
				s2.insert(next);
			} else {
				s1.insert(next);
			}
			vis.insert(next);
			bfsq.push(next);
		}
	}
	cout << s1.size() * s2.size() - (n - 1) << endl;

	
	return 0;
}