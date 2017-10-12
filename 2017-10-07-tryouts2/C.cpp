#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dp[3000002];
int dp2[3000002];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<int> vals;
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; vals.push_back(cur);
	}

	memset(dp, -1, sizeof dp);
	memset(dp2, -1, sizeof dp);
	dp[0] = 0;
	dp2[0] = 0;

	for(int i = 0; i <= 2000000; i++) {
		bool found = false;
		int last = -1;
		for(int jI = 0; jI < vals.size(); jI++) {
			int j = vals[jI];
			if(dp[i+j] == -1) {
				dp[i+j] = dp[i] + 1;
			} else {
				dp[i+j] = min(dp[i+j], dp[i] + 1);
			}
			if(!found && (jI == vals.size() - 1 || vals[jI+1] > i) && i != 0) {
				dp2[i] = dp2[i-j] + 1;
				found = true;
			}
		}
		if(dp[i] != dp2[i]) {
			cout << "non-canonical" << endl;
			return 0;
		}
	}

	cout << "canonical" << endl;
	
	return 0;
}