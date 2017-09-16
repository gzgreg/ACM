#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define PI 3.1415926535

double angle(vector<int> a, vector<int> b) {
	double ans = 0;
	double mag1 = 0, mag2 = 0;
	for(int i = 0; i < 5; i++) {
		ans += a[i] * b[i];
		mag1 += a[i] * a[i];
		mag2 += b[i] * b[i];
	}
	// cout << ans << " " << mag1 << " " << mag2 << endl;
	ans /= sqrt(mag1);
	ans /= sqrt(mag2);
	return ans;
}

vector<int> diff(vector<int>& a, vector<int>& b) {
	vi ans (5);
	for(int i = 0; i < 5; i++) {
		ans[i] = a[i] - b[i];
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<vector<int>> pts;
	for(int i = 0; i < n; i++) {
		int a, b, c, d, e; cin >> a >> b>> c >> d >> e;
		pts.push_back({a, b, c, d, e});
	}

	vector<bool> good(n, true);

	for(int i = 0; i < n; i++) {
		if(!good[i]) continue;
		for(int j = i+1; j < n; j++) {
			for(int k = j+1; k < n; k++) {
				double a1 = angle(diff(pts[i], pts[j]), diff(pts[i], pts[k]));
				double a2 = angle(diff(pts[j], pts[i]), diff(pts[j], pts[k]));
				double a3 = angle(diff(pts[k], pts[i]), diff(pts[k], pts[j]));
				// cout << i << " " << j << " " << k << endl;
				// cout << a1 << " " << a2 << " " << a3 << endl;

				if(a1 > 1e-10) {
					good[i] = false;
				}
				if(a2 > 1e-10) {
					good[j] = false;
				}
				if(a3 > 1e-10) {
					good[k] = false;
				}
			}
		}
	}

	int ans = 0;
	vector<int> ansVec;
	for(int i = 0; i < n; i++) {
		if(good[i]) {
			ans++;
			ansVec.push_back(i+1);
		}
	}
	
	cout << ans << endl;
	for(int i : ansVec) {
		 cout << i << endl;
	}

	return 0;
}