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

	int n, m, k; cin >> n >> m >> k;

	vector<vector<int>> grid(n, vector<int>(m));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	int repl = 0;
	int ans = 0;

	for(int i = 0; i < m; i++) {
		int curColAns = 0;
		int curRepl = 0;
		int numOnes = 0;
		for(int j = 0; j < n; j++) {
			if(grid[j][i] != 1) continue;
			//cout << i << " " << j << " ";
			int curAns = 0;
			for(int l = j; l < j+k && l < n; l++) {
				curAns += grid[l][i];
			}
			if(curAns > curColAns) {
				curColAns = curAns;

				curRepl = numOnes;
			}
			//cout << curAns << " " << curRepl << endl;
			numOnes++;
		}
		ans += curColAns;
		repl += curRepl;
	}

	cout << ans << " " << repl << endl;

	return 0;
}