#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll memo[1000];

ll dp(ll d) {
	if(d == 0) {
		return 0;
	} else if (d == 1) {
		return 1;
	} else if (memo[d] != -1) {
		return memo[d];
	}

	ll bestAns = 0;
	for(ll i = 1; i < d; i++) {
		bestAns = max(bestAns, dp(i) * (d-i));
	}

	bestAns = max(bestAns, d);

	return memo[d] = bestAns;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	memset(memo, -1, sizeof memo);

	while(N--) {
		ll x; cin >> x;
		if(x == 0) {
			cout << 0 << endl;
			continue;
		}
		for(int i = 1; i < 1000; i++) {
			if(dp(i) >= x) {
				cout << i << endl;
				break;
			}
		}
	}
	
	return 0;
}