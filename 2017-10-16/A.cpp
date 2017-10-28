#include <bits/stdc++.h>

using namespace std;

double memo[1001];
double pl, pr; 

double dp(int n) {
	if(n == 0) {
		return 0;
	} else if (memo[n] > -0.5) {
		return memo[n];
	}
	
	double best = 1e9;
	for(int i = 0; i < n; i++) {
		int lsize = i;
		int rsize = n - i - 1;
		
		double expect = 0;
		expect += (dp(lsize) + dp(rsize));
		expect += (pl*(dp(lsize)) + pr*(dp(rsize)) + 1) / (1 - pl - pr);
		best = min(best, expect);
	}
	//cout << n << " " << best << endl;
	return memo[n] = best;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;

	while(true) {
		cin >> n;
		if(n == 0) break;
		cin >> pl >> pr;
		
		for(int i = 0; i <= n; i++) {
			memo[i] = -1;
		}
		
		cout << fixed << setprecision(2) << dp(n) << endl;
	}
	return 0;
}