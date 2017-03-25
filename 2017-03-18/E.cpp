#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define EPS 1e-6

#define PI 3.141592653

ld f(ld x, int a) {
	return sqrt(1 + PI*PI/a/a*cos(PI*x/a)*cos(PI*x/a));
}

ld sim(ld l, ld r, int a) { 
	return (f(l, a) + f(r, a) + 4*f((l+r)/2, a))* (r-l) / 6; 
}
ld adaptive_sim(ld l, ld r, ld simfull, int a) { ld m = (l+r)/2;
  ld siml = sim(l,m, a), simr = sim(m,r, a), cor = (siml+simr-simfull)/15;
  if (abs(cor) < EPS) return siml + simr + cor;
  return adaptive_sim(l,m,siml, a) + adaptive_sim(m,r,simr, a); }

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	while(T--) {
		int a, b, x1, y1, x2, y2; cin >> a >> b >> x1 >> y1 >> x2 >> y2;

		int oldX, oldY, newX, newY; ld ans = 0;

		int numX = x1 % a;
		int numY = y1 % b;

		if(min(numX, a-numX) < min(numY, b-numY)) {
			if(numX == a / 2 && a % 2 == 0) {
				oldX = x1 / a + (x1 < x2);
			} else {
				oldX = (x1 + 0.5*a) / a;
			}
			oldY = y1 / b + (y1 < y2);
			ans += adaptive_sim(0, min(numX, a-numX), sim(0, min(numX, a-numX), a), a) + abs(y1 - oldY * b);
		} else {
			if(numY == b / 2 && b % 2 == 0) {
				oldY = y1 / b + (y1 < y2);
			} else {
				oldY = (y1 + 0.5*b) / b;
			}
			oldX = x1 / a + (x1 < x2);
			ans += adaptive_sim(0, min(numY, b-numY), sim(0, min(numY, b-numY), b), b) + abs(x1 - oldX * a);
		}
		numX = x2 % a;
		numY = y2 % b;

		if(min(numX, a-numX) < min(numY, b-numY)) {
			if(numX == a / 2 && a % 2 == 0) {
				newX = x2 / a + (x1 > x2);
			} else {
				newX = (x2 + 0.5*a) / a;
			}
			newY = y2 / b + (y1 > y2);
			ans += adaptive_sim(0, min(numX, a-numX), sim(0, min(numX, a-numX), a), a) + abs(y2 - newY * b);
		} else {
			if(numY == b / 2 && b % 2 == 0) {
				newY = y2 / b + (y1 > y2);
			} else {
				newY = (y2 + 0.5*b) / b;
			}
			newX = x2 / a + (x1 > x2);
			ans += adaptive_sim(0, min(numY, b-numY), sim(0, min(numY, b-numY), b), b) + abs(x2 - newX * a);
		}

		ans += a * abs(newX-oldX);
		ans += b * abs(newY-oldY);
		if(newX == oldX && newY == oldY) {
			if(min(numX, a-numX) < min(numY, b-numY)
				&& min(x1%a, a-x1%a) < min(y1%b, b-y1%b)) {
				ans -= abs(y2 - newY * b);
				ans -= abs(y1 - oldY * b);
			}
			if(min(numX, a-numX) > min(numY, b-numY)
				&& min(x1%a, a-x1%a) > min(y1%b, b-y1%b)) {
				ans -= abs(x2 - newX * a);
				ans -= abs(x1 - oldX * a);
			}
		}
		cout << (int) (ans + 0.5) << endl;
	}

	
	return 0;
}