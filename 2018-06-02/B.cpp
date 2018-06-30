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
		int n; cin >> n;

		map<int, ll> rows, cols;
		for(int i = 0; i < n; i++) {
			int row, col; cin >> row >> col;

			rows[row]++; cols[col]++;
		}
		ll ans = 0;
		for(auto cur : rows) {
			ans += cur.second * cols[cur.first];
		}
		cout << ans << endl;
	}

	return 0;
}