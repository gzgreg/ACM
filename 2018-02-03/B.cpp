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

	set<pair<int, int>> degree;
	int N, M; cin >> N >> M;
	vector<int> degreeVec(N, 0);
	vector<vector<int>> adj(N, vector<int>());
	for(int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		degreeVec[b]++;
		adj[a].push_back(b);
	}
	for(int i = 0; i < degreeVec.size(); i++) {
		degree.insert({degreeVec[i], i});
	}
	vector<int> ans;
	while(!degree.empty()) {
		auto cur = *(degree.begin());
		degree.erase(degree.begin());

		if(degreeVec[cur.second] != 0) {
			cout << "*" << endl;
			return 0;
		}
		ans.push_back(cur.second);
		for(auto val : adj[cur.second]) {
			degree.erase({degreeVec[val], val});
			degree.insert({degreeVec[val] - 1, val});
			degreeVec[val]--;
		}
	}
	for(auto cur : ans) {
		cout << cur << endl;
	}

	return 0;
}