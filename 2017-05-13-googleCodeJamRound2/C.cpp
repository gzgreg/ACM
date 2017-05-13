#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int R, C; 
bool dfs(int idx, vector<string>& grid, 
	vector<pii>& beams, 
	vector<pair<bool, bool>>& dirs) {
	bool ans = false;
	if(idx == beams.size()) {
		cout << grid[beams[beams.size() - 1].first][beams[beams.size() - 1].second];
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				
				if(grid[i][j] == '.') {
					bool found = false;
					for(int k = i - 1; k >= 0; k++) {
						if(grid[k][j] == '#') break;
						if(grid[k][j] == '|') {
							found = true;
							// cout << "a";
							break;
						}
					}
					for(int k = i + 1; k < R; k++) {
						if(grid[k][j] == '#') break;
						if(grid[k][j] == '|') {
							found = true;
							// cout << "b";
							break;
						}
					}
					for(int k = j - 1; k >= 0; k++) {
						if(grid[i][k] == '#') break;
						if(grid[i][k] == '-') {
							found = true;
							// cout << "c";
							break;
						}
					}
					for(int k = j + 1; k < C; k++) {
						if(grid[i][k] == '#') break;
						if(grid[i][k] == '-') {
							found = true;
							break;
						}
					}
					// cout << i << " " << j << " " << found << endl;
					if(!found) return false;
				}
				
			}
		}
		return true;
	} else {
		if(dirs[idx].first) {
			grid[beams[idx].first][beams[idx].second] = '-';
			ans = ans || dfs(idx + 1, grid, beams, dirs);
			if(ans) return true;
		}
		if(dirs[idx].second) {
			grid[beams[idx].first][beams[idx].second] = '|';
			ans = ans || dfs(idx + 1, grid, beams, dirs);
			if(ans) return true;
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	for(int id = 1; id <= T; id++) {
		cout << "Case #" << id << ": ";

		cin >> R >> C;
		vector<string> grid;
		for(int i = 0; i < R; i++) {
			string curr; cin >> curr; grid.push_back(curr);
		}

		vector<pii> beams;
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				if(grid[i][j] == '|' || grid[i][j] == '-') {
					beams.push_back({i, j});
					grid[i][j] = '|';
				}
			}
		}
		vector<pair<bool, bool>> dirs;
		for(pii curr : beams) {
			dirs.push_back({true, true});
			for(int i = curr.first - 1; i >= 0; i--) {
				if(grid[i][curr.second] == '#') break;
				if(grid[i][curr.second] == '|') {
					dirs[dirs.size() - 1].second = false;
					break;
				}
			}
			for(int i = curr.first + 1; i < R; i++) {
				if(grid[i][curr.second] == '#') break;
				if(grid[i][curr.second] == '|') {
					dirs[dirs.size() - 1].second = false;
					break;
				}
			}
			for(int i = curr.second - 1; i >= 0; i--) {
				if(grid[curr.first][i] == '#') break;
				if(grid[curr.first][i] == '|') {
					dirs[dirs.size() - 1].first = false;
					break;
				}
			}
			for(int i = curr.first + 1; i < C; i++) {
				if(grid[curr.first][i] == '#') break;
				if(grid[curr.first][i] == '|') {
					dirs[dirs.size() - 1].first = false;
					break;
				}
			}
		}
		bool ans = dfs(0, grid, beams, dirs);

		if(ans) {
			cout << "POSSIBLE" << endl;
			for(string s : grid) {
				cout << s << endl;
			}
		} else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	
	return 0;
}