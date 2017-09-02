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

	vector<string> grid1, grid2;
	for(int i = 0; i < n; i++) {
		string s; cin >> s; grid1.push_back(s);
	}

	for(int i = 0; i < n; i++) {
		string s; cin >> s; grid2.push_back(s);
	}

	pii start = {0, 0};
	queue<pii> bfsq; bfsq.push(start);
	map<pii, int> dist; dist[start] = 0;
	while(!bfsq.empty()) {
		pii curr = bfsq.front(); bfsq.pop();
		vector<pii> locs = {{curr.first + 1, curr.second},
							{curr.first - 1, curr.second},
							{curr.first, curr.second + 1},
							{curr.first, curr.second - 1}};
		for(pii loc : locs) {
			if(loc.first < 0 || loc.first >= n
				|| loc.second < 0 || loc.second >= m
				|| dist.count(loc)
				|| grid1[loc.first][loc.second] == '#'){
				continue;
			}

			bfsq.push(loc);
			dist[loc] = dist[curr] + 1;
		}
	}

	if(!dist.count({n-1, m-1})) {
		cout << "NO" << endl;
		return 0;
	}
	int endDist = dist[{n-1, m-1}];

	dist.clear();

	bfsq.push(start);
	dist[start] = 0;
	while(!bfsq.empty()) {
		pii curr = bfsq.front(); bfsq.pop();
		vector<pii> locs = {{curr.first + 1, curr.second},
							{curr.first - 1, curr.second},
							{curr.first, curr.second + 1},
							{curr.first, curr.second - 1}};
		for(pii loc : locs) {
			if(loc.first < 0 || loc.first >= n
				|| loc.second < 0 || loc.second >= m
				|| dist.count(loc)
				|| grid2[loc.first][loc.second] == '#'){
				continue;
			}

			bfsq.push(loc);
			dist[loc] = dist[curr] + 1;
		}
	}

	if(!dist.count({n-1, m-1}) || dist[{n-1, m-1}] != endDist) {
		cout << "NO" << endl;
		return 0;
	}

	dist.clear();
	bfsq.push(start);
	dist[start] = 0;
	while(!bfsq.empty()) {
		pii curr = bfsq.front(); bfsq.pop();
		vector<pii> locs = {{curr.first + 1, curr.second},
							{curr.first - 1, curr.second},
							{curr.first, curr.second + 1},
							{curr.first, curr.second - 1}};
		for(pii loc : locs) {
			if(loc.first < 0 || loc.first >= n
				|| loc.second < 0 || loc.second >= m
				|| dist.count(loc)
				|| grid1[loc.first][loc.second] == '#'
				|| grid2[loc.first][loc.second] == '#'){
				continue;
			}

			bfsq.push(loc);
			dist[loc] = dist[curr] + 1;
		}
	}

	if(dist.count({n-1, m-1}) && dist[{n-1, m-1}] == endDist) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}