#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, k, t1, t2; cin >> n >> k >> t1 >> t2;

	vector<ll> times;
	for(int i = 0; i < n; i++) {
		ll m; cin >> m; times.push_back(m);
	}

	vector<pii> intervals;
	for(int i = 0; i < k; i++) {
		ll bj, ej; cin >> bj >> ej; intervals.push_back({bj, ej});
	}

	set<pii> badTimes;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++) {
			ll l = intervals[j].first - times[i];
			ll r = intervals[j].second - times[i];

			if(r > t1 && l < t2) {
				r = min(r, t2);
				l = max(l, t1);
				badTimes.insert({l, r});
			}
		}
	}

	ll totBad = 0;
	if(badTimes.size() == 0) {
		cout << "1.000000000000000" << endl;
		return 0;
	}
	ll leftEnd = (*(badTimes.begin())).first;
	ll rightEnd = (*(badTimes.begin())).second;
	for(pii cur : badTimes) {
		if(cur.first > rightEnd) {
			totBad += (rightEnd - leftEnd);
			leftEnd = cur.first;
			rightEnd = cur.second;
		} else {
			rightEnd = max(rightEnd, cur.second);
		}
	}

	totBad += rightEnd - leftEnd;
	ll totTime = t2 - t1;

	cout << fixed << setprecision(10) << (double) (totTime - totBad) / totTime << endl;
	
	return 0;
}