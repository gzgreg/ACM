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
	
	int n, q, c; cin >> n >> q >> c;

	map<pii, vector<int>> bright;

	for(int i = 0; i < n; i++) {
		int xi, yi, si; cin >> xi >> yi >> si;
		bright[{xi, yi}].push_back(si);
	}

	vector<vector<vector<int>>> cumsum;
	for(int i = 0; i < 20; i++) {
		cumsum.push_back(vector<vector<int>> (0));
		for(int x = 0; x <= 100; x++) {
			cumsum[i].push_back(vector<int>(101, 0));
			for(int y = 0; y <= 100; y++) {
				if(x == 0 || y == 0) {
					cumsum[i][x][y] = 0;
				} else {
					cumsum[i][x][y] = cumsum[i][x-1][y] + cumsum[i][x][y-1] - cumsum[i][x-1][y-1];
					for(int cur : bright[{x, y}]) {
						cumsum[i][x][y] += (cur + i) % (c+1);
					}
				}
			}
		}
	}

	// for(int i = 0; i < 10; i++) {
	// 	for(int j = 0; j < 10; j++) {
	// 		cout << cumsum[2][i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	for(int i = 0; i < q; i++) {
		int t, x1, y1, x2, y2; cin >> t >> x1 >> y1 >> x2 >> y2;

		t %= c+1;
		x1--; y1--;
		int ans = 0;
		ans += cumsum[t][x2][y2];
		ans -= cumsum[t][x1][y2];
		ans -= cumsum[t][x2][y1];
		ans += cumsum[t][x1][y1];

		cout << ans << endl;
	}

	return 0;
}