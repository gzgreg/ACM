#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000000009

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<pii> cmd;
		for(int i = 0; i < n; i++) {
			int pi, ei; cin >> pi >> ei; cmd.push_back({pi, ei});
		}

		vector<int> height(5000, 0);
		ll ans = 0;
		for(int i = 0; i < n; i++) {
			pii curr = cmd[i];
			int cost = 0;

			for(int j = curr.first+2500; j <= 5000; j++) {
				height[j] += curr.second;
				cost++;
				if(abs(height[j] - height[j+1]) < 1.5) break;
			}
			for(int j = curr.first - 1+2500; j >= 0; j--) {
				if(abs(height[j] - height[j+1]) > 1.5) {
					cost++;
					height[j] += curr.second;
				} else {
					break;
				}
			}
			// cout << cost << endl;
			// for(int i = 0; i < 20; i++) {
			// 	cout << height[i + 995] << " ";
			// }
			// cout << endl;
			ans += (ll) (i+1) * cost;
			ans %= MOD;
		}

		cout << ans << endl;
	}
	
	
	return 0;
}