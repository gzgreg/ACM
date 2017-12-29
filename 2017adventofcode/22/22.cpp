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
	
	vector<string> gridS;
	string s;
	while(getline(cin, s)) {
		gridS.push_back(s);
	}
	map<pair<int, int>, int> grid;
	for(int i = 0; i < gridS.size(); i++) {
		for(int j = 0; j < gridS[0].size(); j++) {
			grid[{i, j}] = (gridS[i][j] == '#' ? 2 : 0);
		}
	}

	pii curLoc;
	curLoc.first = gridS.size() / 2;
	curLoc.second = gridS[0].size() / 2;

	complex<int> dir(-1, 0);
	int ans = 0;
	for(int i = 0; i < 10000000; i++) {
		if(grid[{curLoc.first, curLoc.second}] == 2) {
			dir *= complex<int>(0, -1);
		} else if (grid[{curLoc.first, curLoc.second}] == 0){
			dir *= complex<int>(0, 1);
		} else if (grid[{curLoc.first, curLoc.second}] == 3) {
			dir *= -1;
		}

		if(grid[{curLoc.first, curLoc.second}] == 1) {
			ans++;
		}
		grid[{curLoc.first, curLoc.second}] += 1;
		grid[{curLoc.first, curLoc.second}] %= 4;

		curLoc.first += dir.real();
		curLoc.second += dir.imag();
	}
	cout << ans << endl;

	return 0;
}