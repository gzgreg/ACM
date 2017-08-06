#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int memo[5005][5005];

vector<vector<bool>> isPalindrome(5005, vector<bool>(5005, false));

int dp(int l, int r) {
	if(l == r) {
		return 0;
	} else if (l == r-1) {
		return 1;
	} else if (memo[l][r] != -1) {
		return memo[l][r];
	}

	int subSize = (r-l) / 2;
	if(!isPalindrome[l][r]) {
		return memo[l][r] = 0;
	}

	return memo[l][r] = dp(l, l+subSize)+1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(memo, -1, sizeof memo);

	string s; cin >> s;
	int n = s.size();

	for(int i = 0; i < n; i++) {
		int l = i, r = i;
		isPalindrome[l][r+1] = true;

		while(l >= 0 && r < n && s[l] == s[r]) {
			isPalindrome[l][r+1] = true;
			l--;
			r++;
		}
		if(i < n-1 && s[i] == s[i+1]) {
			int l = i, r = i+1;
			isPalindrome[l][r+1] = true;

			while(l >= 0 && r < n && s[l] == s[r]) {
				isPalindrome[l][r+1] = true;
				l--;
				r++;
			}
		}
	}

	vector<int> ans(n, 0);
	for(int i = 0; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			int maxVal = dp(i, j);
			for(int k = 0; k < maxVal; k++) {
				ans[k]++;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	
	return 0;
}