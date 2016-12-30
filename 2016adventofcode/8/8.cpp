#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	vector<vector<bool>> grid(50, vector<bool> (6, false));

	string s;
	while(getline(cin, s)) {
		if(s[1] == 'e') {
			bool inFirst = true;
			int x, y;
			string xStr = "", yStr = "";
			for(int i = 5; i < s.size(); i++) {
				if(s[i] == 'x') {
					inFirst = false;
					x = atoi(xStr.c_str());
				} else if (inFirst) {
					xStr.push_back(s[i]);
				} else {
					yStr.push_back(s[i]);
				}
			}
			y = atoi(yStr.c_str());
			for(int i = 0; i < x; i++) {
				for(int j = 0; j < y; j++) {
					grid[i][j] = true;
				}
			}
		} else {
			if(s[7] == 'c') {
				int col, dist;
				string colStr = "", distStr = "";
				bool inCol = true;
				for(int i = 16; i < s.size(); i++) {
					if(s[i] == ' ') {
						inCol = false;
						col = atoi(colStr.c_str());
						i += 3;
					} else if (inCol) {
						colStr.push_back(s[i]);
					} else {
						distStr.push_back(s[i]);
					}
				}
				dist = atoi(distStr.c_str());
				vector<int> newVec;
				for(int i = 0; i < 6; i++) {
					newVec.push_back(grid[col][(i - dist + 6) % 6]);
				}
				for(int i = 0; i < 6; i++) {
					grid[col][i] = newVec[i];
				}
			} else {
				int col, dist;
				string colStr = "", distStr = "";
				bool inCol = true;
				for(int i = 13; i < s.size(); i++) {
					if(s[i] == ' ') {
						inCol = false;
						col = atoi(colStr.c_str());
						i += 3;
					} else if (inCol) {
						colStr.push_back(s[i]);
					} else {
						distStr.push_back(s[i]);
					}
				}
				dist = atoi(distStr.c_str());
				vector<int> newVec;
				for(int i = 0; i < 50; i++) {
					newVec.push_back(grid[(i - dist + 50) % 50][col]);
				}
				for(int i = 0; i < 50; i++) {
					grid[i][col] = newVec[i];
				}
			}
		}
	}
	int total = 0;
	for(int i = 0; i < 50; i++) {
		for(int j = 0; j < 6; j++) {
			total += grid[i][j];
			cout << (grid[i][j] ? '#' : ' ');
		}
		cout << endl;
	}
	cout << total << endl;
	
	return 0;
}