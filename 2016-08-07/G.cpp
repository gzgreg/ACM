#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int m, n;

vector<vector<bool>> invalid;

long long memo[24][2][2][2];

long long dp(int col, bool otop, bool omid, bool obot) {
	if(otop && invalid[0][col]) return 0;
	if(omid && invalid[1][col]) return 0;
	if(obot && invalid[2][col]) return 0;
	if(memo[col][otop][omid][obot] != -1) return memo[col][otop][omid][obot];
	bool top = otop || invalid[0][col];
	bool mid = omid || invalid[1][col];
	bool bot = obot || invalid[2][col];
	if(col == m-1) {
		if(top) {
			if(mid || bot) return 1;
			return 2;
		} else if (mid) {
			return 1;
		} else if (bot) {
			return 2;
		}
		return 3;
	}
	long long ans;
	if(top) {
		if(mid && bot){
			ans = dp(col+1, false, false, false);
		} else if(mid){ 
			ans = dp(col+1, false, false, false) + dp(col+1, false, false, true);
		} else if(bot) {
			ans = dp(col+1, false, false, false) + dp(col+1, false, true, false);
		} else {
			ans = 2*dp(col+1, false, false, false) + dp(col+1, false, false, true)
				+ dp(col+1, false, true, true) + dp(col+1, false, true, false);
		}
	} else if (mid) {
		if(bot) {
			ans = dp(col+1, false, false, false) + dp(col+1, true, false, false);
		} else {
			ans = dp(col+1, false, false, false) + dp(col+1, false, false, true)
				+ dp(col+1, true, false, true) + dp(col+1, true, false, false);
		}
		
	} else if (bot) {
		ans = 2*dp(col+1, false, false, false) + dp(col+1, true, false, false)
			+ dp(col+1, true, true, false) + dp(col+1, false, true, false);
	} else {
		ans = 3*dp(col+1, false, false, false) + 2*dp(col+1, false, false, true)
			+ 2*dp(col+1, true, false, false) + dp(col+1, false, true, false)
			+ dp(col+1, true, true, false) + dp(col+1, false, true, true)
			+ dp(col+1, true, false, true) + dp(col+1, true, true, true);
	}
	memo[col][otop][omid][obot] = ans;
	return ans;
}

int main(){
	ios::sync_with_stdio(0);

	cin >> m >> n;

	memset(memo, -1, sizeof memo);

	for(int i = 0; i < 3; i++) {
		invalid.push_back(vector<bool>(m, false));
	}

	for(int i = 0; i < n; i++) {
		double x, y; cin >> x >> y;
		invalid[floor(y)][floor(x)] = true;
	}

	cout << dp(0, false, false, false) << endl;
	
	return 0;
}