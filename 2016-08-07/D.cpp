#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int n, m; cin >> n >> m;

	set<pii> idx;
	int map[n][m];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			char curr; cin >> curr;
			if(curr == '.') {
				map[i][j] = 0;
				idx.insert({i, j});
			} else {
				map[i][j] = -1;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		idx.insert({i, -1});
		idx.insert({i, m});
	}
	for(int i = 0; i < m; i++) {
		idx.insert({-1, i});
		idx.insert({n, i});
	}
	int max = -1;
	while(!idx.empty()) {
		set<pii> newIdx;
		max++;
		for(pii curr : idx) {
			int x, y; x = curr.first; y = curr.second;
			int newX = x-1;
			if(newX >= 0 && y >= 0 && y < m && map[newX][y] == -1) {
				map[newX][y] = max + 1;
				newIdx.insert({newX, y});
			}
			newX = x+1;
			if(newX < n && y >= 0 && y < m && map[newX][y] == -1) {
				map[newX][y] = max + 1;
				newIdx.insert({newX, y});
			}
			int newY = y-1;
			if(newY >= 0 && x >= 0 && x < n && map[x][newY] == -1) {
				map[x][newY] = max + 1;
				newIdx.insert({x, newY});
			}
			newY = y+1;
			if(newY < m && x >= 0 && x < n && map[x][newY] == -1) {
				map[x][newY] = max + 1;
				newIdx.insert({x, newY});
			}
		}
		idx = newIdx;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << (max < 10 || map[i][j] >= 10 ? "." : "..");
			if(map[i][j] == 0) {
				cout << ".";
			} else {
				cout << map[i][j];
			}
		}
		cout << endl;
	}
	
	return 0;
}