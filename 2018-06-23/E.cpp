#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll n, m; cin >> n >> m;

	vector<ll> tests;
	for(ll i = 0; i < n; i++) {
		ll k; cin >> k;
		ll testVal = 0;
		for(ll j = 0; j < k; j++) {
			ll soln; cin >> soln;
			testVal += (1LL << (soln - 1));
		}
		//cout << bitset<30>(testVal) << endl;
		tests.push_back(testVal);
	}
	ll bestCount = n+1;
	ll bestSet;
	for(ll i = 1; i < (1LL << (n+1)); i++) {
		ll cur = 0;
		ll count = 0;
		ll curSet = 0;

		//cout << bitset<10>(i) << endl;
		for(ll j = 0; j < n; j++) {
			if((i & (1LL << j)) != 0) {
				//cout << j << endl;
				cur = cur | tests[j];
				curSet += (1 << j);
				count++;
			}
		}
		//cout << cur << endl;
		//cout << bitset<10>(cur) << endl;
		if(cur == (1LL << m) - 1 && count < bestCount) {
			bestCount = count;
			bestSet = curSet;
		}
	}

	cout << bestCount << endl;
	//cout << bestSet << endl;
	for(ll i = 0; i < n; i++) {
		if(bestSet & (1LL << i)) {
			cout << i+1 << " ";
		}
	}
	cout << endl;
	
	return 0;
}