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

	int ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;

	complex<double> a(ax, ay),
		b(bx, by),
		c(cx, cy);

	complex<ld> v1 = b - a, v2 = c - b;
	if(abs(abs(v1) - abs(v2)) > 1e-12) {
		cout << "No" << endl;
		return 0;
	}
	if(abs(v1.real()*v2.imag() - v1.imag()*v2.real()) < 1e-12) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	
	return 0;
}