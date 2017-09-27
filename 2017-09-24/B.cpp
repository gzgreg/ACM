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

	ll n, p, q, r; cin >> n >> p >> q >> r;

	vector<ll> vals;
	for(int i = 0; i < n; i++) {
		ll cur; cin >> cur; vals.push_back(cur);
	}

	ll leftVal = vals[0];
	vector<ll> bestRight (n);

	if(r > 0) {
		ll rightVal = -1e9;
		for(int i = n-1; i >= 0; i--) {
			rightVal = max(rightVal, vals[i]);
			bestRight[i] = rightVal;
		}
	} else {
		ll rightVal = 1e9;
		for(int i = n-1; i >= 0; i--) {
			rightVal = min(rightVal, vals[i]);
			bestRight[i] = rightVal;
		}
	}
	ll bestAns = -5e18;
	for(int i = 0; i < n; i++) {
		if(p > 0) {
			leftVal = max(leftVal, vals[i]);
		} else {
			leftVal = min(leftVal, vals[i]);
		}
		bestAns = max(bestAns, p*leftVal + q*vals[i] + r*bestRight[i]);
	}

	cout << bestAns << endl;
	
	return 0;
}