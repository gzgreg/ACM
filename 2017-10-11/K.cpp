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

	int n, k; cin >> n >> k;
	vector<pair<int, pii>> point(k);

	for(int i = 0; i < k; i++) {
		cin >> point[i].second.first;
		cin >> point[i].second.second;
		cin >> point[i].first;
	}

	map<int, set<pii>> points;

	for(int i = 0; i < k; i++) {
		pii center = point[i].second;
		int bound = point[i].first;
		int xmin = max(0, center.first - (int) cbrt(bound) - 3);
		int xmax = min(n, center.first + (int) cbrt(bound) + 3);
		int ymin = max(0, center. second - (int) cbrt(bound) - 3);
		int ymax = min(n, center.second + (int) cbrt(bound) + 3);
		for(int j = xmin; j <= xmax; j++) {
			int start = -1, end = -1;
			bool found = false;
			for(int k = ymin; k <= ymax; k++) {
				ll dx = (center.first - j);
				ll dy = (center.second - k);
				if(abs(dx*dx*dx) + abs(dy*dy*dy) <= bound) {
					if(!found) {
						start = k;
						found = true;
					}
				} else {
					if(found) {
						end = k;
						found = false;
						break;
					}
				}
			}
			if(found) {
				end = ymax + 1;
			}
			if(start != -1)
				points[j].insert({start, end});
		}
	}
	int remove = 0;
	for(auto cur : points) {
		int curStart = -1, curEnd = -1;
		if(cur.second.size() == 0) continue;
		for(pii interval : cur.second) {
			if(curStart == -1) {
				curStart = interval.first;
				curEnd = interval.second;
			} else if (interval.first <= curEnd) {
				curEnd = max(curEnd, interval.second);
			} else {
				remove += curEnd - curStart;
				curStart = interval.first;
				curEnd = interval.second;
			}
		}

		remove += curEnd - curStart;
	}

	ll ans = (n+1);
	ans *= (n+1);
	cout << ans - remove << endl;
	
	return 0;
}