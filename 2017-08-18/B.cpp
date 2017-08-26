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

	int n, m; cin >> n >> m;

	vector<int> vals;
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; vals.push_back(cur);
	}

	vector<set<int>> edges (n);
	map<pii, int> edgeMap;

	vector<pii> deg;
	for(int i = 0; i < n; i++) {
		deg.push_back({0, i});
	}

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		if(!edges[a].count(b)) {
			deg[a].first++;
			deg[b].first++;
		}
		edges[a].insert(b);
		edges[b].insert(a);
		edgeMap[{a, b}] = i+1;
		edgeMap[{b, a}] = i+1;
	}
	set<pii> degSet;
	for(pii cur : deg) {
		if(vals[cur.second] == -1) continue;
		degSet.insert(cur);
	}
	vector<int> curDeg (n);
	for(int i = 0; i < n; i++) {
		curDeg[i] = 0;
	}
	set<int> ans;

	while(!degSet.empty()) {
		pii cur = *(degSet.begin());
		degSet.erase(degSet.begin());

		if(cur.first == 0 && vals[cur.second] != -1
			&& vals[cur.second] != curDeg[cur.second] % 2) {
			cout << -1 << endl;
			return 0;
		}

		if(vals[cur.second] != -1
			&& vals[cur.second] != curDeg[cur.second] % 2) {
			ans.insert(edgeMap[{cur.second, *(edges[cur.second].begin())}]);
			curDeg[cur.second]++;
			curDeg[*(edges[cur.second].begin())]++;
		}

		for(int i : edges[cur.second]) {
			degSet.erase({edges[i].size(), i});

			edges[i].erase(cur.second);
			if(vals[i] != -1) degSet.insert({edges[i].size(), i});
		}
	}

	cout << ans.size() << endl;
	for(int i : ans) {
		cout << i << endl;
	}
	return 0;
}