#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define PI 3.141592653

double minDist(complex<double> v, complex<double> w, complex<double> p) {
  const double l2 = norm(v-w);

  const double t = max(0.0, min(1.0, (conj(p-v) * (w-v)).real() / l2));
  const complex<double> proj = v + t * (w - v);  // Projection falls on the segment
  return abs(p-proj);
}

int main(){
	ios::sync_with_stdio(0);

	int R, l, w; cin >> R >> l >> w;

	int T; cin >> T;
	while(T--) {
		double A, B; cin >> A >> B;

		double ans = 100000;

		// ans = min(ans, l * (A > PI / 2 ? 1 : sin(A)));
		// ans = min(ans, max(w * sin(PI/2 - B), sqrt((w-l*sin(B))*(w-l*sin(B)) + l*l*cos(B)*cos(B))));
		// cout << fixed << setprecision(10) << ans / 2 << endl;
		complex<double> bEnd (l-l*cos(B), l*sin(B));
		ans = minDist(complex<double>(l, w), complex<double>(l-l*cos(A), w+l*sin(A)), complex<double>(0, w));
		ans = min(ans, minDist(complex<double>(l, w), complex<double>(l-l*cos(A), w+l*sin(A)), bEnd));
		ans = min(ans, minDist(complex<double>(l, w), complex<double>(10000, w), bEnd));
		ans = min(ans, minDist(bEnd, complex<double>(l, 0), complex<double>(l, w)));

		cout << fixed << setprecision(10) << min(ans / 2, (double)R) << endl;
	}
	
	return 0;
}