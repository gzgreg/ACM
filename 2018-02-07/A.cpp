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

	ll t; cin >> t;
	vector<ll> powers;
	powers.push_back(1);
	for(ll i = 0; i < 10; i++) {
		powers.push_back(powers.back() * 26);
	}
	while(t--) {
		ll k; cin >> k;
		ll pow = 26;
		vector<ll> ans;
		ll len = 0;
		for(auto cur : powers) {
			if(k >= cur) {
				k -= cur;
				len++;
			} else break;
		}
		while(k > 0) {
			ll cur = k % pow;
			k /= pow;
			ans.push_back(cur);
		}
		// if(ans[ans.size() - 1] == 0) {
		// 	ans.erase(--ans.end());
		// }
		while(ans.size() < len) ans.push_back(0);
		reverse(ans.begin(), ans.end());
		for(auto cur : ans) {
			cout << (char) ('A' + cur);
		}
		cout << endl;
	}
	
	return 0;
}