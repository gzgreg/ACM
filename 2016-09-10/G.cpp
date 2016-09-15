#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int j, p, H, L;
double v0;
double g = 9.81;
double PI = 3.14159265358979324;

double h(double l) {
	if (l < 0) return H;
	else if (l < L / 2.0) {
		return H * (1 - 2 * (l*l) / (L*L));
	} else if (l < L) {
		return 2 * H * pow((l/L - 1), 2);
	} else return 0;
}

double dhdl(double l) {
	if (l < L / 2.0) {
		return -4 * H * l / (L*L);
	} else if (l < L) {
		return 4 * H * l / (L*L) - 4.0 * H / (double) L;
	} else return 0;
}

double f(double l) {
	return -1 * g / 2 * (l*l) / (v0*v0) + H + p;
}

int main(){
	ios::sync_with_stdio(0);
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> j >> p >> H >> L;
		v0 = sqrt(2 * g * j);
	
		double pl = 0.0;
		double pr = v0 * sqrt(2 * (H + p) / g);
		double l = (pl + pr) / 2;
		do {
//			cout << f(l) << " " << h(l) << endl;
		
			if (f(l) - h(l) > 0) {
				pl = l;
				l = (pl + pr) / 2.0;
			} else {
				pr = l;
				l = (pl + pr) / 2.0;
			}
		} while (abs(f(l) - h(l)) > 1e-5);

		double vl = sqrt(2 * g * (j + p + (H - h(l))));

		double v1, v2;
		v1 = -1 * g * l / (v0*v0);
		v2 = dhdl(l);
		double angle = (1 + v1 * v2) / (sqrt(1+(v1*v1)) * sqrt(1+(v2*v2)));
		angle = acos(angle);
		angle *= (180 / PI);
	
		cout << fixed << setprecision(5) << l << " " << vl << " " << angle << endl;
	}
	return 0;
}
