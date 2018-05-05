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
	for(int id = 1; id <= T; id++) {
		cout << "Case #" << id << ": ";
		ll R, B, C; cin >> R >> B >> C;
		vector<vector<ll>> cashiers;
		for(int i = 0; i < C; i++) {
			int Mi, Si, Pi; cin >> Mi >> Si >> Pi;
			cashiers.push_back({Mi, Si, Pi});
		}

		ll ans = 0;
		for(ll i = (1LL << 61); i > 0; i >>= 1) {
			ll curAns = ans + i;
			vector<ll> cashierRes(C, 0);
			for(int j = 0; j < C; j++) {
				vector<ll> curCash = cashiers[j];
				cashierRes[j] = max(0LL, min(curCash[0], (curAns - curCash[2]) / curCash[1]));
			}
			// cout << curAns << endl;
			// 	for(auto cur : cashierRes) cout << cur << " ";
			// 	cout << endl;
			sort(cashierRes.begin(), cashierRes.end());
			reverse(cashierRes.begin(), cashierRes.end());
			ll totBits = 0;
			for(int j = 0; j < R; j++) {
				totBits += cashierRes[j];
			}
			if(totBits < B) ans = curAns;
			//if(i == 1) {
			//}
		}
		cout << ans+1 << endl;
	}

	return 0;
}