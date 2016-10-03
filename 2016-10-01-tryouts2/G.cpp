#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int grid[1000][1000];
ll n, m, L, R;

pii mem[1000][1000];

pii dp (int x, int y) {
	pii retVal;
	if(x == 0 && y == 0) {
		return {grid[0][0], grid[0][0]};
	} else if (mem[x][y].first != -1) {
		return mem[x][y];
	} else if (x == 0) {
		retVal = {dp(x, y-1).first + grid[x][y], dp(x, y-1).second + grid[x][y]};
	} else if (y == 0) {
		retVal = {dp(x-1, y).first + grid[x][y], dp(x-1, y).second + grid[x][y]};
	} else {
		retVal = {min(dp(x-1, y).first, dp(x, y-1).first) + grid[x][y], 
					max(dp(x-1, y).second, dp(x, y-1).second) + grid[x][y]};
	}
	mem[x][y] = retVal;
	return retVal;
}

int main(){
	ios::sync_with_stdio(0);
	
	int T; cin >> T;
	while(T--) {
		cin >> n >> m >> L >> R;
		memset(grid, 0, sizeof grid);
		for(int i = 0; i < 1000; i++) {
			for(int j = 0; j < 1000; j++) {
				mem[i][j] = {-1, -1};
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}
		cout << (!(dp(n-1, m-1).first > R || dp(n-1, m-1).second < L) ? "Yes" : "No") << endl;
	}

	return 0;
}