#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;

	for(int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		int p, x, y; cin >> p >> x >> y;

		double dist = sqrt((x-50)*(x-50) + (y-50)*(y-50));
		if(dist > 50) {
			cout << "white" << endl;
			continue;
		}

		complex<double> loc (x-50, y-50);

		double angle = arg(loc) * 360 / 2 / 3.141592653;
		angle = -angle + 360;
		angle = angle + 90;
		if(angle > 360) angle = angle - 360;

		if(angle > (double) p * 360 / 100) {
			cout << "white" << endl;
		} else {
			cout << "black" << endl;
		}
	}
	
	return 0;
}