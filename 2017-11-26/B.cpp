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

	ll n, x, k; cin >> n >> x >> k;
	vector<ll> a;
	for(int i = 0; i < n; i++) {
		ll cur; cin >> cur; a.push_back(cur);
	}

	map<ll, ll> num, mult, orig;
	for(int i = 0; i < n; i++) {
		num[a[i] / x]++;
		if(a[i] % x == 0) {
			mult[a[i] / x]++;
		} else {
			orig[a[i]]++;
		}
	}

	map<ll, vector<ll>> sz;
	for(auto cur : orig) {
		sz[cur.first / x].push_back(cur.second);
	}

	ll ans = 0;
	auto num2 = num;
	for(auto cur : num) {
		ll notMult = cur.second - mult[cur.first];
		if(k == 0) {
			ans += notMult*(notMult-1)/2;
			for(auto val : sz[cur.first]) {
				ans += val*(val-1)/2;
				ans += val;
			}
		} else {
			ans += mult[cur.first]*num2[cur.first + (k-1)];
			ans += notMult*(num2[cur.first + k]);
		}
	}

	cout << ans << endl;
	
	return 0;
}