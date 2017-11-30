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
	
	int n; cin >> n;
	string s; cin >> s;

	vector<int> cumsum(n+1);
	map<int, vector<int>> vals;
	vals[0].push_back(0);
	for(int i = 0; i < n; i++) {
		cumsum[i+1] = cumsum[i] + (s[i] == '1' ? 1 : -1);

		vals[cumsum[i+1]].push_back(i+1);
	}
	int ans = 0;
	for(auto cur : vals) {
		ans = max(ans, cur.second.back() - cur.second.front());
	}

	cout << ans << endl;

	return 0;
}