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

	vector<int> plus, minus;

	for(int i = 0; i < n; i++) {
		int si, ai; cin >> si >> ai;
		if(si == 1) {
			plus.push_back(ai);
		} else {
			minus.push_back(ai);
		}
	}

	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());

	int m; cin >> m;
	for(int i = 0; i < m; i++) {
		int xi; cin >> xi;

		int ans = 0;
		if(plus.size() != 0) {
			int l = 0, r = plus.size() - 1;

			while(l < r) {
				int mid = (l + r) / 2;
				if (plus[mid] <= xi) {
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			ans += l;
			if(plus[l] <= xi) ans++;
		}
		xi = -xi;
		if(minus.size() > 0) {
			int l = 0, r = minus.size() - 1;

			while(l < r) {
				int mid = (l + r) / 2;
				if (minus[mid] <= xi) {
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			//cout << l << ' ' << r << endl;
			ans += l;
			if(minus[l] <= xi) ans++;
		}

		//cout << "a" << ans << endl;
		cout << ans << endl;
	}

	return 0;
}