#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'
#define MOD 1000000007

int w, h;

vector<vector<int>> memo;

int dp(int tiles, int idx){
	if(tiles < 0) return 0;
	if(idx == 0){
		if(tiles <= h){
			return 1;
		} else return 0;
	}
	if(memo[tiles][idx]) return memo[tiles][idx];
	int ans = 0;
	for(int i = 0; i <= h; i++){
		if(tiles-i < 0) break;
		ans += dp(tiles-i, idx - 1);
		ans %= MOD;
	}
	memo[tiles][idx] = ans;
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	
	int n; cin >> n >> w >> h;

	memo = vector<vector<int>> (n+1, vector<int> (w+1, 0));

	int total = 0;
	for(int i = 0; i <= n; i++){
		total += dp(i, w-1);
		total %= MOD;
		//cout << dp(i, w-1) << endl;
	}

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= w-1; j++){
			cout << memo[i][j] << " ";
		}
		cout << endl;
	}

	cout << total - ((int)floor(n/w)+1) << endl;

	return 0;
}