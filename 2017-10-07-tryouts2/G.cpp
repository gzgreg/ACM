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
	set<pii> points;
	for(int i = 0; i < n; i++) {
		int xi, yi; cin >> xi >> yi;
		points.insert({xi, yi});
	}

	int ans = 0;

	for(auto i : points) {
		set<pii> nextPts;
		nextPts.insert({i.first, i.second + 2018});
		nextPts.insert({i.first, i.second - 2018});
		nextPts.insert({i.first + 2018, i.second});
		nextPts.insert({i.first - 2018, i.second});

		nextPts.insert({i.first + 1680, i.second + 1118});
		nextPts.insert({i.first + 1680, i.second - 1118});
		nextPts.insert({i.first - 1680, i.second + 1118});
		nextPts.insert({i.first - 1680, i.second - 1118});

		nextPts.insert({i.first + 1118, i.second + 1680});
		nextPts.insert({i.first + 1118, i.second - 1680});
		nextPts.insert({i.first - 1118, i.second + 1680});
		nextPts.insert({i.first - 1118, i.second - 1680});
		for(auto j : nextPts) {
			if(points.count(j)) {
				ans++;
			}
		}
	}

	cout << ans / 2 << endl;

	return 0;
}