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

	vector<pii> tests;
	for(int i = 0; i < n; i++) {
		int ti, ci; cin >> ti >> ci;
		tests.emplace_back(ti, ci);
	}

	vector<int> ans (n);

	priority_queue<pii> q;

	int idx = 0;
	int day = 1;
	while(idx < n) {
		do {
			q.push({tests[idx].second - tests[idx].first, idx});
			idx++;
		} while (idx < n && tests[idx].first == tests[idx-1].first);
		while(!q.empty() && (idx == n || max(day, tests[q.top().second].first) < tests[idx].first)) {
			auto cur = q.top(); q.pop();
			ans[cur.second] = max(day, tests[cur.second].first);
			day = ans[cur.second] + 1;
		}
	}
	// while(!q.empty()) {
	// 	auto cur = q.top(); q.pop();
	// 	ans[cur.second] = max(day, tests[cur.second].first);
	// 	day = ans[cur.second] + 1;
	// }

	for(int i : ans) {
		cout << i << " ";
	}
	cout << endl;
	
	return 0;
}