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

	int n, m, k, t; cin >> n >> m >> k >> t;
	vector<int> people, vaults;

	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; people.push_back(cur);
	}

	for(int i = 0; i < m; i++) {
		int cur; cin >> cur; vaults.push_back(cur);
	}

	sort(people.begin(), people.end());
	sort(vaults.begin(), vaults.end());

	int vi = 0;
	int curCap = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		while((people[i] - vaults[vi]) > t) {
			vi++;
			curCap = 0;
			if(vi == m) break;
		}
		if(abs(people[i] - vaults[vi]) <= t) {
			ans++;
			curCap++;
			if(curCap == k) {
				curCap = 0;
				vi++;
				if(vi == m) break;
			}
		}
	}
	
	cout << ans << endl;

	return 0;
}
