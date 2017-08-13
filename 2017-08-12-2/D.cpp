#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int memo[201][6001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(memo, -1, sizeof memo);

	int n, k; cin >> n >> k;
	vector<ll> nums(n);
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	vector<pii> fac(n);
	for(int i = 0; i < n; i++) {
		while(nums[i] % 2 == 0) {
			fac[i].first++;
			nums[i] /= 2;
		}
		while(nums[i] % 5 == 0) {
			fac[i].second++;
			nums[i] /= 5;
		}
	}
	memo[0][0] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = k-1; j >= 0; j--) {
			for(int k = 6000 - fac[i].second; k >= 0; k--) {
				if(memo[j][k] == -1) continue;
				memo[j+1][k+fac[i].second] = max(memo[j+1][k+fac[i].second], memo[j][k] + fac[i].first);
			}
		}
	}
	int best = 0;
	for(int i = 0; i <= 6000; i++) {
		best = max(best, min(i, memo[k][i]));
	}

	cout << best << endl;
	return 0;
}