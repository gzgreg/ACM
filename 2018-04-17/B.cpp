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
	vector<string> grid;
	for(int i = 0; i < n; i++) {
		string cur; cin >> cur; grid.push_back(cur);
	}

	set<vector<int>> vals;

	for(int i = 0; i < n; i++) {
		vector<int> curVals;
		for(int j = 0; j < m; j++) {
			if(grid[i][j] == '#') curVals.push_back(j);
		}
		vals.insert(curVals);
	}

	vector<vector<int>> groups;
	for(auto cur : vals) groups.push_back(cur);

	bool good = true;
	for(int i = 0; i < groups.size(); i++) {
		for(int j = i+1; j < groups.size(); j++) {
			set<int> numVals;
			for(auto cur : groups[i]) numVals.insert(cur);
			for(auto cur : groups[j]) numVals.insert(cur);

			if(numVals.size() != groups[i].size() + groups[j].size()) {
				good = false;
				break;
			}
		}
	}
	
	if(good) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}