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
	
	int k, n, m; cin >> k >> n >> m;

	vector<pair<pii, vector<string>>> vals;

	for(int i = 0; i < k; i++) {
		vector<string> cur;
		int tot = 0;
		for(int j = 0; j < n; j++) {
			string s; cin >> s;
			for(int k = 0; k < m; k++) {
				tot += s[k] == '1';
			}
			cur.push_back(s);
		}
		vals.push_back({{tot, i}, cur});

	}

	sort(vals.begin(), vals.end());

	vector<vector<int>> ans (n, vector<int>(m));
	vector<int> res(k);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(vals[0].second[i][j] == '1') {
				ans[i][j] = k;
			}
		}
	}
	for(int a = 1; a < k; a++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(vals[a].second[i][j] == '0'
					&& vals[a-1].second[i][j] == '1') {
					cout << "IMPOSSIBLE" << endl;
					return 0;
				}
				if(vals[a].second[i][j] == '1'
					&& vals[a-1].second[i][j] == '0') {
					ans[i][j] = k-a;
				}
			}
		}
	}

	for(int i = 0; i < k; i++) {
		res[vals[i].first.second] = k-i;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	for(int i : res) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}