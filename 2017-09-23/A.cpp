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

	int n, m; cin >> n >> m;

	vector<pii> vals;
	for(int i = 0; i < n; i++) {
		int a, s; cin >> a >> s; vals.push_back({a, s});
	}

	sort(vals.begin(), vals.end());

	priority_queue<int, vector<int>, greater<int>> times;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		pii curStart = vals[i];
		while(!times.empty()) {
			int cur = times.top();
			if(cur > curStart.first) break;
			times.pop();
			if(cur + m >= curStart.first) {
				ans++;
				break;
			}
		}
		times.push(curStart.first + curStart.second);
	}

	cout << ans << endl;
	
	return 0;
}