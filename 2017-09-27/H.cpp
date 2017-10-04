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
	while(T--) {
		int n, m; cin >> n >> m;
		vector<string> grid;
		for(int i = 0; i < n; i++) {
			string s; cin >> s; grid.push_back(s);
		}

		int numOnes = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				numOnes += (grid[i][j] == '1');
			}
		}

		if(numOnes < 2*n + 2*m - 4) {
			cout << -1 << endl;
			continue;
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			ans += grid[i][0] == '0';
			ans += grid[i][m-1] == '0';
		}

		for(int i = 0; i < m; i++) {
			ans += grid[0][i] == '0';
			ans += grid[n-1][i] == '0';
		}
		ans -= grid[0][0] == '0';
		ans -= grid[0][m-1] == '0';
		ans -= grid[n-1][0] == '0';
		ans -= grid[n-1][m-1] == '0';
		cout << ans << endl;
	}

	return 0;
}