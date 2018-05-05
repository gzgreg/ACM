#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const double EPS = 1e-10;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	for(int id = 1; id <= T; id++) {
		cout << "Case #" << id << ": ";
		int N, P; cin >> N >> P;
		vector<pair<ld, ld>> cookies;
		for(int i = 0; i < N; i++) {
			int w, h; cin >> w >> h; cookies.push_back({w, h});
		}

		ld minRange = 0, maxRange = 0;

		ld base = 0;

		for(auto cur : cookies) {
			base += 2*cur.first + 2*cur.second;
		}
		P -= base;
		ld ans = 0;
		for(auto cur : cookies) {
			minRange += 2*min(cur.first, cur.second);
			maxRange += 2*sqrt(cur.first*cur.first + cur.second*cur.second);
			if(minRange < P + EPS) {
				ans = min((ld) P, maxRange);
			} else break;
		}
		cout << fixed << setprecision(10) << ans + base << endl;
	}
	
	return 0;
}