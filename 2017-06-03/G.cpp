#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int P; cin >> P;
	while(P--) {
		int K, x, y; cin >> K >> x >> y;

		if(y > x) {
			cout << K << " " << 2 << " " << x << " " << y << endl;
		} else {
			if(y < 4) {
				cout << K << " NO PATH" << endl;
			} else {
				int d = x + 5 - y;
				cout << K << " " << 6 << " ";
				cout << 1 << " " << 2 << " " << 3 << " ";
				cout << d << " " << x + 2 << " " << x + 3<< endl;
			}
		}
	}
	
	return 0;
}