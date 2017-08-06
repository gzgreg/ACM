#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

struct val {
	ll p;
	ll j;
	ll id;
};

vector<val> vals;

vector<vector<pii>> memo;
ll n;
int numToPick;
int start;

pii dp(ll idx, ll num) {
	if (idx >= n) {
		if(num <= 0) return {0, 0};
		return {-1e7, -1e7};
	} else if (memo[idx][num].first != -1) {
		return memo[idx][num];
	}
	int numJanPicked = numToPick - num;
	int numPetraPicked = idx - numJanPicked + start;
	if(numJanPicked < numPetraPicked) {
		pii ans1 = dp(idx+1, num);
		ans1.second += vals[idx].p;
		pii ans2 = dp(idx+1, num-1);
		ans2.first += vals[idx].j;
		if(ans1 > ans2) {
			return memo[idx][num] = ans1;
		} else {
			return memo[idx][num] = ans2;
		}
	} else {
		pii ans1 = dp(idx+1, num);
		ans1.second += vals[idx].p;

		pii ans2 = dp(idx+2, num-1);
		ans2.second += vals[idx].p;
		if(idx + 1 < n) ans2.first += vals[idx+1].j;
		if(ans1 > ans2) {
			return memo[idx][num] = ans1;
		} else {
			return memo[idx][num] = ans2;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	ll t; cin >> t;
	while(t--) {
		memo = vector<vector<pii>> (1005, vector<pii>(1005, {-1, -1}));
		cin >> n;
		string s; cin >> s;
		bool pTurn = (s[0] == 'P');

		auto cmp2 = [&](val a, val b) {
			if(a.p != b.p) {
				return a.p > b.p;
			} else if (a.j != b.j) {
				return a.j < b.j;
			}
			return a.id < b.id;
		};
		set<val, decltype(cmp2)> ppref(cmp2);

		for(ll i = 0; i < n; i++) {
			ll pi, ji; cin >> pi >> ji;
			ppref.insert({pi, ji, i});
		}

		vals = vector<val>(ppref.begin(), ppref.end());

		ll pVal, jVal;
		if(pTurn) {
			numToPick = n/2;
			start = 0;
			std::tie(jVal, pVal) = dp(1, n/2);
			pVal += vals[0].p;
		} else {
			numToPick = (n+1) / 2;
			start = 1;
			std::tie(jVal, pVal) = dp(0, (n+1)/2);
		}

		cout << pVal << " " << jVal << endl;
	}
	
	return 0;
}