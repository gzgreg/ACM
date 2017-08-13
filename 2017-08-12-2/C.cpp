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
	
	int n, a, b; cin >> n >> a  >> b;
	vector<pii> vals;
	for(int i = 0; i < n; i++) {
		int xi, yi; cin >> xi >> yi; vals.push_back({xi, yi});
	}
	int best = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			pii x = vals[i], y = vals[j];
			if(x.first + y.first <= a
				&& x.second <= b && y.second <= b) {
				best = max(best, x.first*x.second + y.first*y.second);
			}
			if(x.first + y.second <= a
				&& x.second <= b && y.first <= b) {
				best = max(best, x.first*x.second + y.first*y.second);
			}

			swap(x.first, x.second);

			if(x.first + y.first <= a
				&& x.second <= b && y.second <= b) {
				best = max(best, x.first*x.second + y.first*y.second);
			}
			if(x.first + y.second <= a
				&& x.second <= b && y.first <= b) {
				best = max(best, x.first*x.second + y.first*y.second);
			}

			swap(y.first, y.second);

			if(x.first + y.first <= a
				&& x.second <= b && y.second <= b) {
				best = max(best, x.first*x.second + y.first*y.second);
			}
			if(x.first + y.second <= a
				&& x.second <= b && y.first <= b) {
				best = max(best, x.first*x.second + y.first*y.second);
			}

			swap(x.first, x.second);

			if(x.first + y.first <= a
				&& x.second <= b && y.second <= b) {
				best = max(best, x.first*x.second + y.first*y.second);
			}
			if(x.first + y.second <= a
				&& x.second <= b && y.first <= b) {
				best = max(best, x.first*x.second + y.first*y.second);
			}

			swap(y.first, y.second);
			swap(a, b);
						if(x.first + y.first <= a
				&& x.second <= b && y.second <= b) {
				best = max(best, x.first*x.second + y.first*y.second);
			}
			if(x.first + y.second <= a
				&& x.second <= b && y.first <= b) {
				best = max(best, x.first*x.second + y.first*y.second);
			}

			swap(x.first, x.second);

			if(x.first + y.first <= a
				&& x.second <= b && y.second <= b) {
				best = max(best, x.first*x.second + y.first*y.second);
			}
			if(x.first + y.second <= a
				&& x.second <= b && y.first <= b) {
				best = max(best, x.first*x.second + y.first*y.second);
			}

			swap(y.first, y.second);

			if(x.first + y.first <= a
				&& x.second <= b && y.second <= b) {
				best = max(best, x.first*x.second + y.first*y.second);
			}
			if(x.first + y.second <= a
				&& x.second <= b && y.first <= b) {
				best = max(best, x.first*x.second + y.first*y.second);
			}

			swap(x.first, x.second);

			if(x.first + y.first <= a
				&& x.second <= b && y.second <= b) {
				best = max(best, x.first*x.second + y.first*y.second);
			}
			if(x.first + y.second <= a
				&& x.second <= b && y.first <= b) {
				best = max(best, x.first*x.second + y.first*y.second);
			}

			swap(y.first, y.second);
		}
	}

	cout << best << endl;

	return 0;
}