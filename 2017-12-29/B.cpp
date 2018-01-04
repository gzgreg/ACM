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
		string s; cin >> s; grid.push_back(s);
	}

	string instr; cin >> instr;

	vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	vector<int> perm = {0, 1, 2, 3};

	pii startLoc;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(grid[i][j] == 'S') {
				startLoc = {i, j};
				break;
			}
		}
	}
	int ans = 0;
	do {
		bool good = false;
		pii curLoc = startLoc;
		for(char cur : instr) {
			string curInstr; curInstr.push_back(cur);
			int idx = stoi(curInstr);
			auto curDir = dir[perm[idx]];

			pii nextLoc = curLoc;
			nextLoc.first += curDir.first;
			nextLoc.second += curDir.second;

			if(nextLoc.first < 0 || nextLoc.first >= n
				|| nextLoc.second < 0 || nextLoc.second >= m) {
				good = false;
				break;
			}

			if(grid[nextLoc.first][nextLoc.second] == '#') {
				good = false;
				break;
			}

			if(grid[nextLoc.first][nextLoc.second] == 'E')  {
				good = true;
				break;
			}
			curLoc = nextLoc;
		}
		ans += good;
	} while(next_permutation(perm.begin(), perm.end()));

	cout << ans << endl;
	
	return 0;
}