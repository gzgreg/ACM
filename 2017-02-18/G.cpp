#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

map<ll, ll> disc;

ll solve(ll numDisc, ll start, ll dest) {
	ll maxDisc = disc[numDisc];
	set<ll> newPegs = {0, 1, 2};
	newPegs.erase(start);
	newPegs.erase(dest);
	ll newPeg = *(newPegs.begin());
	if(numDisc == 1) {
		if(maxDisc == start) {
			return 0;
		} else if (maxDisc == dest) {
			return 1;
		} else {
			return -1;
		}
	}
	if(maxDisc == start) {
		ll tmp = solve(numDisc - 1, start, newPeg);
		if(tmp == -1) {
			return -1;
		} else {
			return tmp;
		}
	} else if(maxDisc == dest) {
		ll tmp = solve(numDisc - 1, newPeg, dest);
		if(tmp == -1) {
			return -1;
		} else {
			return (1LL << (numDisc - 1)) + tmp;
		}
	} else {
		return -1;
	}
}

int main(){
	ios::sync_with_stdio(0);

	ll total = 0;
	for(ll i = 0; i < 3; i++) {
		ll len; cin >> len; total += len;

		for(ll j = 0; j < len; j++) {
			ll curr; cin >> curr; disc[curr] = i;
		}
	}

	if(total == 0) {
		cout << 0 << endl;
		return 0;
	}

	ll ans = solve(total, 0, 2);
	ll tot = (1LL << total) - 1;
	if(ans != -1) {
		cout << tot - ans << endl;
	} else {
		cout << "No" << endl;
	}
	
	return 0;
}