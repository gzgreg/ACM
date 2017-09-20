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

	ll n, m, q; cin >> n >> m >> q;

	ll cumSumA = 0;
	for(ll i = 0; i < n; i++) {
		ll cur; cin >> cur;
		if(i % 2) {
			cumSumA -= cur;
		} else {
			cumSumA += cur;
		}
	}

	vector<ll> b;
	for(ll i = 0; i < m; i++) {
		ll cur; cin >> cur; b.push_back(cur);
	}

	ll cumSumB = 0;
	set<ll> cumsums;

	for(ll i = 0; i < m; i++) {
		if(i < n) {
			if(i % 2) {
				cumSumB += b[i];
			} else {
				cumSumB -= b[i];
			}
		} else {
			cumsums.insert(cumSumB);
			cumSumB *= -1;
			cumSumB -= b[i - n];
			if(n % 2) {
				cumSumB -= b[i];
			} else {
				cumSumB += b[i];
			}
		}
	}
	cumsums.insert(cumSumB);
	while(q--) {
		auto ans = cumsums.lower_bound(-cumSumA);
		auto ans2 = cumsums.upper_bound(-cumSumA);
		auto bestAns = *ans2;
		if(ans == cumsums.end() || ans == ans2) {
			ans--;
		}
		if(ans != cumsums.end() && ans2 != cumsums.end()) {
			if(abs(*ans + cumSumA) < abs(*ans2 + cumSumA)) {
				bestAns = *ans;
			} 
		} else if (ans != cumsums.end()) {
			bestAns = *ans;
		}

		cout << abs(bestAns + cumSumA) << endl;
		
		int li, ri, xi; cin >> li >> ri >> xi;

		if(!((ri - li) % 2)) {
			if(li % 2) {
				cumSumA += xi;
			} else {
				cumSumA -= xi;
			}
		}
	}
	auto ans = cumsums.lower_bound(-cumSumA);
	auto ans2 = cumsums.upper_bound(-cumSumA);
	auto bestAns = *ans2;
	if(ans == cumsums.end() || ans == ans2) {
		ans--;
	}
	if(ans != cumsums.end() && ans2 != cumsums.end()) {
		if(abs(*ans + cumSumA) < abs(*ans2 + cumSumA)) {
			bestAns = *ans;
		} 
	} else if (ans != cumsums.end()) {
		bestAns = *ans;
	}

	cout << abs(bestAns + cumSumA) << endl;
	
	return 0;
}