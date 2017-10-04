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

	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		vector<ll> vals(n);
		for(int i = 0; i < n; i++) {
			cin >> vals[i];
		}
		ll ans = 0;
		for(ll i = 0; i <= 25; i++) {
			ll curSegSize = 0;
			for(int j = 0; j < n; j++) {
				if(bitset<25>(vals[j])[i]) {
					curSegSize++;
				} else {
					ans += (1LL << i) * curSegSize * (curSegSize + 1) / 2;
					curSegSize = 0;
				}
			}
			ans += (1 << i) * curSegSize * (curSegSize + 1) / 2;
		}
		cout << ans << endl;
	}
	
	return 0;
}