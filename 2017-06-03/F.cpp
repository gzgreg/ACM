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
		ll K, p, q; char junk; cin >> K >> p >> junk >> q;

		int upSteps = p / q;
		p = p % q;
		ll tmp = q-p;
		p = q;
		q = tmp;
		q += p * upSteps;

		cout << K << " " << p << "/" << q << endl;
	}
	
	return 0;
}