#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, r, p;

ll memo[1000001];

ll dp(ll curN) {
	if(curN == 1) {
		return 0;
	} else if (memo[curN] != -1) {
		return memo[curN];
	}
	ll bestAns = 1e17;
	for(ll i = 2; i <= curN; i++) {
		ll curAns = 0;
		curAns += r;
		curAns += (i-1) * p;
		curAns += dp((curN + i - 1) / i);
		bestAns = min(bestAns, curAns);
	}

	return memo[curN] = bestAns;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> r >> p;
	memset(memo, -1, sizeof memo);
	cout << dp(n) << endl;

	return 0;
}