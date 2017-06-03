#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m; 
vector<pii> vals;
int memo[16][2];

int dp(int floor, bool left) {
	if(floor == n-1) return left ? vals[n-1].second : (m+1-vals[n-1].first);
	if(memo[floor][left] != -1) return memo[floor][left];

	int ans = dp(floor+1, 1) + (left ? (vals[floor].second * 2 + 1)
					: (m+2));
	int ans2 = dp(floor+1, 0) + (left ? (m+2)
					: ((m+1-vals[floor].first)*2+1));
	return memo[floor][left] = min(ans, ans2);
}

int main(){
	ios::sync_with_stdio(0);

	cin >> n >> m;

	memset(memo, -1, sizeof memo);
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		int min = -1, max = -1;
		for(int j = 0; j < s.size(); j++) {
			if(s[j] == '1') {
				min = j;
				break;
			}
		}
		for(int j = s.size() - 1; j >= 0; j--) {
			if(s[j] == '1') {
				max = j;
				break;
			}
		}
		vals.push_back({min, max});
	}

	reverse(vals.begin(), vals.end());
	vector<pii> tmpVals;
	int extra = 0;
	int tmpExtra = 0;
	for(auto val : vals) {
		if(val.first != -1) {
			tmpVals.push_back(val);
			extra += tmpExtra;
			tmpExtra = 0;
		} else {
			tmpExtra++;
		}
	}
	vals = tmpVals;
	n = tmpVals.size();
	if(n == 0) {
		cout << 0 << endl;
	} else {
		cout << dp(0, 1) + extra << endl;
	}
	
	return 0;
}