#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int x, y; cin >> x >> y;
	int n; cin >> n;
	vector<pair<int, ld>> shields;
	int unshielded = y;
	for(int i = 0; i < n; i++) {
		int li, ui; ld fi; cin >> li >> ui >> fi;
		shields.push_back({ui - li, fi});
		unshielded -= ui - li;
	}

	ld l = -1e9;
	ld r = 1e9;
	ld diff = (r - l) / 2.0;

	while(r - l > 1e-8) {
		ld mid = (l + r) / 2.0;
		ld ans = unshielded * mid;
		for(pair<int, ld> shield : shields) {
			ans += shield.first * mid * shield.second;
		}
		if(ans > x) {
			r -= diff;
		} else {
			l += diff;
		}
		diff = diff / 2;
	}

	cout << fixed << setprecision(10) << l << endl;
	
	return 0;
}