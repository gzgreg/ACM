#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define PI 3.141592653

double f(vector<double>& coeff, double x) {
	double pow = 1;
	double ans = 0;
	for(double curr : coeff) {
		ans += curr*pow;
		pow *= x;
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	
	int n; int i = 0;
	while(cin >> n) {
		i++;
		vector<double> coeff;
		for(int i = 0; i <= n; i++) {
			double curr; cin >> curr; coeff.push_back(curr);
		}
		double l, r, inc; cin >> l >> r >> inc;

		vector<double> marks;
		double currVol = 0;

		vector<double> sqr (2*n + 2);
		for(int i = 0; i < coeff.size(); i++) {
			for(int j = 0; j < coeff.size(); j++) {
				sqr[i + j] += coeff[i]*coeff[j];
			}
		}

		vector<double> integral; integral.push_back(0);
		for(int i = 0; i < sqr.size(); i++) {
			integral.push_back(sqr[i] / (i+1));
		}

		double totVol = PI*(f(integral, r) - f(integral, l));
		for(double i = inc; i <= totVol; i += inc) {
			double ll = l; double rr = r;
			
			while(rr - ll > 1e-5) {
				double mid = (ll + rr) / 2;
				double diff = (rr - ll) / 2;
				if(PI*(f(integral, mid) - f(integral, l)) > i) {
					rr -= diff;
				} else {
					ll += diff;
				}
			}
			marks.push_back(ll);
			if(marks.size() == 8) break;
		}
		cout << fixed << setprecision(2);
		cout << "Case " << i << ": " << totVol << endl;
		if(marks.size() == 0) {
			cout << "insufficient volume" << endl;
		} else {
			for(double mark : marks) {
				cout << mark - l << " ";
			}
			cout << endl;
		}
	}

	return 0;
}