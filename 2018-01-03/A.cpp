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

	string s; cin >> s;

	map<char, int> cnt;

	for(auto cur : s) {
		cnt[cur]++;
	}
	
	int ans = 1e9;
	ans = min(ans, cnt['B']);
	ans = min(ans, cnt['u'] / 2);
	ans = min(ans, cnt['l']);
	ans = min(ans, cnt['b']);
	ans = min(ans, cnt['a'] / 2);
	ans = min(ans, cnt['s']);
	ans = min(ans, cnt['r']);

	cout << ans << endl;

	return 0;
}