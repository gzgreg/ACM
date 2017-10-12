#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

double sinh(double x) {
	return (exp(x) - exp(-x)) / 2;
}

double cosh(double x) {
	return (exp(x) + exp(-x)) / 2;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	double d, s; cin >> d >> s;

	double l = 0, r = 1e6;

	while(r - l > 1e-10) {
		double mid = (l + r) / 2;
		if(mid + s > mid * cosh(d / 2/mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}

	cout << fixed << setprecision(10) << 2*l*sinh(d / 2/l) << endl;
	
	return 0;
}