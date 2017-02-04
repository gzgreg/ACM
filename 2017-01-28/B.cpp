#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int N; cin >> N;

	while(N--) {
		double T; cin >> T;
		int X; cin >> X;
		double rad = X * 3.14159265 / 180.0;
		
		double bounceLength = 0.85 / tan(rad);

		while(T > -1e-10) {
			T -= bounceLength;
		}
		T += bounceLength;

		double range = 0.16 / cos(rad);

		if(T - (bounceLength / 2) > 1e-10) {
			T -= bounceLength / 2;
			if(abs(0.425 - T*tan(rad)) - range < 1e-10) {
				cout << "yes" << endl;
			} else {
				cout << "no" << endl;
			}
		} else {
			if(abs(T * tan(rad)) - range < 1e-10) {
				cout << "yes" << endl;
			} else {
				cout << "no" << endl;
			}
		}
	}
	
	return 0;
}