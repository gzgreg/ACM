#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<ld> pt;

#define PI 3.141592653L

ld cp(const pt& a, const pt& b) { return imag(conj(a)*b); }
// SIGNED distance. Pt on the right of vector (a -> b) will be NEGATIVE.
inline ld lp_dist(const pt &a, const pt &b, const pt &p) {
  return cp(b - a, p - a) / abs(b - a); }

int main(){
	ios::sync_with_stdio(0);
	
	int T; cin >> T;

	while(T--) {
		int x1, y1, x2, y2, x3, y3; 
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

		complex<ld> p1 (x1, y1), p2(x2, y2), p3(x3, y3);

		complex<ld> c = abs(p1-p2)*p3 + abs(p1-p3)*p2 + abs(p2-p3)*p1;
		c /= abs(p1-p2) + abs(p1-p3) + abs(p2-p3);

		ld ans = 0;
		ans += abs(c-p1) + abs(c-p2) + abs(c-p3);

		int dist = abs(lp_dist(p1, p2, c));

		for(int i = 1; i <= dist; i++) {
			ans += PI*i*2;
		}

		cout << fixed << setprecision(10) << ans << endl;
	}

	return 0;
}