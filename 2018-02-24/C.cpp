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

	ll T; cin >> T;
	while(T--) {
		ll N; cin >> N;
		multiset<ll> sz;
		for(ll i = 0; i < N; i++) {
			ll cur; cin >> cur; sz.insert(cur);
		}
		ll ans = 0;

		while(sz.size() != 1) {
			auto it = sz.begin();
			ll n1 = *it;
			ll n2 = *(++it);
			ans += n1 + n2;
			sz.erase(it);
			sz.erase(sz.begin());
			sz.insert(n1 + n2);
		}

		cout << ans << endl;
	}
	
	return 0;
}