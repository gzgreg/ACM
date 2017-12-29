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

	vector<string> grid;
	string s;
	while(getline(cin, s)) {
		grid.push_back(s);
		cout << s << endl;
	}
	pii loc;
	for(int i = 0; i < grid[0].size(); i++) {
		if(grid[0][i] == '|') {
			loc = {0, i};
			break;
		}
	}

	vector<int> dx = {1, 0, -1, 0};
	vector<int> dy = {0, 1, 0, -1};

	int dir = 0;
	int tot = 0;
	while(true) {
		cout << loc.first << " " << loc.second << " " << grid[loc.first][loc.second] << endl;

		pii nextLoc = loc;
		nextLoc.first += dx[dir];
		nextLoc.second += dy[dir];
		tot++;
		loc = nextLoc;
		if(grid[loc.first][loc.second] == '+') {
			nextLoc = loc;
			nextLoc.first += dx[(dir+1) % 4];
			nextLoc.second += dy[(dir+1) % 4];
			if(nextLoc.first >= 0
				&& nextLoc.second >= 0
				&& nextLoc.first < grid.size()
				&& nextLoc.second < grid[0].size()
				&& grid[nextLoc.first][nextLoc.second] != ' ') {
				dir = dir+1;
				dir %= 4;
			} else {
				nextLoc = loc;
				nextLoc.first += dx[(dir+3) % 4];
				nextLoc.second += dy[(dir+3) % 4];

				if(nextLoc.first >= 0
				&& nextLoc.second >= 0
				&& nextLoc.first < grid.size()
				&& nextLoc.second < grid[0].size()
				&& grid[nextLoc.first][nextLoc.second] != ' ') {
					dir = dir+3;
					dir %= 4;
				} else {
					break;
				}
			}
		} else if (grid[loc.first][loc.second] >= 'A'
			&& grid[loc.first][loc.second] <= 'Z') {
			cout << grid[loc.first][loc.second] << endl;
		}
		cout << tot << endl;
	}
	
	return 0;
}