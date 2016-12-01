#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'
#define MOD 1000000007

vector<vector<long long>> mem(1000001, vector<long long>(2, -1));

long long dp(int i, bool full) {
	if(i == 0) {
		return full ? 1 : 0;
	} else if (i == 1) {
		return full ? 2 : 4;
	} else if (mem[i][full] != -1) {
		return mem[i][full];
	} else {
		long long ans = 0;
		if(full) {
			ans += dp(i-1, 1) * 2;
			ans %= MOD;
			ans += dp(i-2, 1);
			ans %= MOD;
			ans += dp(i-1, 0);
			ans %= MOD;
		} else {
			ans += dp(i-1, 1) * 4;
			ans %= MOD;
			ans += dp(i-1, 0);
			ans %= MOD;
		}
		mem[i][full] = ans;
		return ans;
	}
}

int main(){
	ios::sync_with_stdio(0);

	mem[0][0] = 0;
	mem[0][1] = 1;
	mem[1][0] = 4;
	mem[1][1] = 2;

	for(int i = 2; i <= 1000000; i++) {
		long long ans = 0;
		ans += mem[i-1][1] * 2;
		ans %= MOD;
		ans += mem[i-2][1];
		ans %= MOD;
		ans += mem[i-1][0];
		ans %= MOD;
		mem[i][1] = ans;
		ans = 0;
		ans += mem[i-1][1] * 4;
		ans %= MOD;
		ans += mem[i-1][0];
		ans %= MOD;
		mem[i][0] = ans;
	}

	int T; cin >> T;
	while(T--) {
		int N; cin >> N; cout << mem[N][1] << endl;
	}
	
	return 0;
}