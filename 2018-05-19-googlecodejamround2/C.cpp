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

	int T; cin >> T;

	for(int id = 1; id <= T; id++) {
		cout << "Case #" << id << ": ";

		int N; cin >> N;

		vector<vector<int>> grid(N, vector<int>(N));
		map<int, map<int, vector<int>>> loc;
		map<int, map<int, set<int>>> colLoc;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				cin >> grid[i][j];
				loc[grid[i][j]][i].push_back(j);
				colLoc[grid[i][j]][j].insert(i);
			}
		}
		int ans = 0;
		for(auto cur : loc) {
			map<int, vector<int>> onlyOneInRow;

			for(auto val : cur.second) {
				vector<int> rowLocs = val.second;
				int row = val.first;
				if(rowLocs.size() != 1) {
					ans += rowLocs.size() - 1;
					bool found = false;
					for(auto curCol : rowLocs) {
						if((curCol == rowLocs.back() && !found)
							|| colLoc[cur.first][curCol].size() == 1) {
							onlyOneInRow[curCol].push_back(row);
							found = true;
						} else {
							colLoc[cur.first][curCol].erase(row);
						}
					}
				} else {
					onlyOneInRow[rowLocs[0]].push_back(row);
				}
			}
			for(auto val : onlyOneInRow) {
				ans += val.second.size() - 1;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}