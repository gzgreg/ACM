#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

map<ll, bool> vals;
vector<ll> factorials = {2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000};
void createVals(ll curr) {
	if(vals[curr]) return;
	vals[curr] = true;

	for(int i = 0; i < factorials.size(); i++) {
		if(curr > 1e18 / factorials[i] + 3) return;
		createVals(curr * factorials[i]);
	}
}

int main(){
	ios::sync_with_stdio(0);
	int n; cin >> n;
	createVals(1);
	while(n--) {
		long long ai; cin >> ai;
		if(vals.count(ai)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}