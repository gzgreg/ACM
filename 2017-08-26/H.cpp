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

	vector<complex<double>> p1, p2;

	for(int i = 0; i < 3; i++) {
		int a, b; cin >> a >> b; p1.push_back({a, b});
	}

	for(int i = 0; i < 3; i++) {
		int a, b; cin >> a >> b; p2.push_back({a, b});
	}

	vector<double> a1, a2;

	for(int i = 0; i < 3; i++) {
		complex<double> a, b;
		a = p1[(i+1) % 3] - p1[i];
		b = p1[(i+2) % 3] - p1[i];
		double cur1 = a.real()*b.real() + a.imag()*b.imag();
		cur1 /= abs(a);
		cur1 /= abs(b);

		a = p2[(i+1) % 3] - p2[i];
		b = p2[(i+2) % 3] - p2[i];
		double cur2 = a.real()*b.real() + a.imag()*b.imag();
		cur2 /= abs(a);
		cur2 /= abs(b);

		a1.push_back(cur1);
		a2.push_back(cur2);
	}

	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());

	for(int i = 0; i < 3; i++) {
		if(abs(a1[i] - a2[i]) > 1e-9) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}