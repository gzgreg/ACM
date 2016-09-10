#include <bits/stdc++.h>

using namespace std;

double tx, ty, s1, s2, theta;
bool flip = false;
double PI = 3.1415926535897932385;

pair<double, double> transform (pair<double, double> init) {
	double x1 = init.first * s1;
	double y1 = init.second * s2;
	double x2 = x1 * cos(theta) - y1 * sin(theta);
	double y2 = x1 * sin(theta) + y1 * cos(theta);
	double x3 = x2 + tx; double y3 = y2 + ty;

	return {x3, y3};
}

int main() {
	int H, W; cin >> H >> W;
	pair<double, double> ll, lr, ur;
	cin >> ll.first >> ll.second >> lr.first >> lr.second >> ur.first >> ur.second;
	tx = ll.first; ty = ll.second;
	s1 = sqrt(pow(lr.first - ll.first, 2) + pow(lr.second - ll.second, 2)) / W;
	s2 = sqrt(pow(ur.first - lr.first, 2) + pow(ur.second - lr.second, 2)) / H;
	pair<double, double> v1, v2;
	v1.first = lr.first - ll.first; v1.second = lr.second - ll.second;
	v2.first = ur.first - lr.first; v2.second = ur.second - lr.second;
	if (v1.first * v2.second - v1.second * v2.first < 0) flip = true;
	if (flip) {
		s1 *= -1;
		theta = atan2((lr.second - ll.second), (lr.first - ll.first)) - PI;
	} else {
		theta = atan2((lr.second - ll.second), (lr.first - ll.first));
	}
	pair<double, double> a = {0, 0};
	for (int i=0; i<10000; i++) {
		a = transform(a);
	}
	cout << fixed << setprecision(5) << a.first << " " << a.second << endl;
	return 0;
}
