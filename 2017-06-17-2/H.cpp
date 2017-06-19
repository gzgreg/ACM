#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	vector<pair<int, pii>> vals;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int curr; cin >> curr;
			vals.push_back({curr, {i + 1, j + 1}});
		}
	}

	sort(vals.begin(), vals.end());
	reverse(vals.begin(), vals.end());

	if(vals[0].second.first != vals[1].second.first
		&& vals[0].second.second != vals[1].second.second) {
		int best1 = 0, best2 = 0;
		for(int i = 0; i < n*m; i++) {
			if(vals[i].second.first == vals[0].second.first
				|| vals[i].second.second == vals[1].second.second) {
				continue;
			}
			best1 = max(best1, vals[i].first);
		}
		for(int i = 0; i < n*m; i++) {
			if(vals[i].second.first == vals[1].second.first
				|| vals[i].second.second == vals[0].second.second) {
				continue;
			}
			best2 = max(best2, vals[i].first);
		}
		if(best1 < best2) {
			cout << vals[0].second.first << " " << vals[1].second.second << endl;
		} else {
			cout << vals[1].second.first << " " << vals[0].second.second << endl;
		}
		
		return 0;
	}

	if(vals[0].second.first == vals[1].second.first) {
		int last = 0;
		for(int i = 0; i < n*m; i++) {
			if(vals[i].second.first != vals[0].second.first) {
				last = i;
				break;
			}
		}
		cout << vals[0].second.first << " " << vals[last].second.second << endl;
	} else {
		int last = 0;
		for(int i = 0; i < n*m; i++) {
			if(vals[i].second.second != vals[0].second.second) {
				last = i;
				break;
			}
		}
		cout << vals[last].second.first << " " << vals[0].second.second << endl;
	}
	
	return 0;
}