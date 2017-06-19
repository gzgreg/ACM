#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;

	vector<vector<int>> grid;
	vector<int> minRow (100, 1000);
	vector<int> minCol (100, 1000);
	for(int i = 0; i < n; i++) {
		grid.push_back(vector<int>());
		for(int j = 0; j < m; j++) {
			int curr; cin >> curr; grid[i].push_back(curr);
			minRow[i] = min(minRow[i], curr);
			minCol[j] = min(minCol[j], curr);
		}
	}
	vector<pair<pii, bool>> moves;
	if(n < m) {
		for(int i = 0; i < n; i++) {
			moves.push_back({{i, minRow[i]}, 0});
			for(int j = 0; j < m; j++) {
				grid[i][j] -= minRow[i];
				minCol[j] = min(minCol[j], grid[i][j]);
			}
		}

		for(int i = 0; i < m; i++) {
			moves.push_back({{i, minCol[i]}, 1});
			for(int j = 0; j < n; j++) {
				grid[j][i] -= minCol[i];
				if(grid[j][i] != 0) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	} else {
		for(int i = 0; i < m; i++) {
			moves.push_back({{i, minCol[i]}, 1});
			for(int j = 0; j < n; j++) {
				grid[j][i] -= minCol[i];
				minRow[j] = min(minRow[j], grid[j][i]);
			}
		}

		for(int i = 0; i < n; i++) {
			moves.push_back({{i, minRow[i]}, 0});
			for(int j = 0; j < m; j++) {
				grid[i][j] -= minRow[i];
				if(grid[i][j] != 0) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}

	int totMoves = 0;

	for(pair<pii, bool> curr : moves) {
		totMoves += curr.first.second;
	}
	
	cout << totMoves << endl;

	for(pair<pii, bool> curr : moves) {
		for(int i = 0; i < curr.first.second; i++) {
			cout << (curr.second ? "col " : "row ") << curr.first.first + 1 << endl;
		}
	}

	return 0;
}