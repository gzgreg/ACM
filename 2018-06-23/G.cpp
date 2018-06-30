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

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int k, n; cin >> k >> n;

	vector<pii> c;
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; c.push_back({cur, i});
	}

	sort(c.begin(), c.end());

	vector<int> ans(n);

	int idx = 0;
	while(k > 0) {
		ans[c[idx].second] += min(k, c[idx].first);
		k -= min(k, c[idx].first);
		idx++;
	}

	for(auto cur : ans) {
		cout << cur << " ";
	}
	cout << endl;
	
	return 0;
}