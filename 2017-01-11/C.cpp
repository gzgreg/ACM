#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int memo[2][3100];

int dp(int N) {
	if (N==1) memset(memo, 0, sizeof memo)
}

int main(){
	ios::sync_with_stdio(0);
	
	int T; cin >> T;
	memset(memo, -1, sizeof memo);

	for(int id = 1; id <= T; id++) {
		int N, K; cin >> N >> K;

		dp(N, (N*(N+1) / 2));

		int ans = 0;
		for(int i = K; i <= N*(N+1) / 2; i++) {
			ans += memo[N][i];
			ans %= 10007;
		}
		cout << "Case " << id << ": " << ans << endl;
	}

	return 0;
}