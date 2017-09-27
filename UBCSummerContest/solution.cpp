#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int maxp = 50;
ld prob[50001][50];
ld dp[50001][50];

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	int n; cin >> n;

	ld p2; cin >> p2; p2 /= 1e6; ld p4 = 1 - p2;

	memset(prob, 0.0, sizeof prob);
	memset(dp, 0.0, sizeof dp);

	for (int len = 1; len <= n; len++) { 
		for (int pow = 1; pow < maxp; pow++) {
			prob[len][pow] += prob[len-1][pow-1] * prob[len][pow-1];
			if (pow == 1) prob[len][pow] = 1;
			if (pow == 2){
				prob[len][pow] = p4;
				if(len != 1) prob[len][pow] += p2*p2;
			}
		}
	}

	// prob[i][j] = probability that tile i ends with value 2^j or greater
	
		cout << fixed << setprecision(5);
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j < maxp; j++) {
			cout << prob[i][j] << " ";
		}
		cout << endl;
	}
	
	for(int len = 0; len <= n; len++) {
		for(int pow = 1; pow < maxp-1; pow++) {
			prob[len][pow] = prob[len][pow] - prob[len][pow+1];
		}
	}

	// prob[i][j] = probability that tile i ends with value 2^j



	// dp[i][j] = expected total of tiles i to 1, given that tile i has value 2^j
	for(int len = 1; len <= n; len++) {
		for(int pow = 1; pow < maxp; pow++) {
			if(pow == 1) {
				ld norm = 1.0 - prob[len-1][1];
				for(int nextPow = 2; nextPow < maxp; nextPow++) {
					dp[len][pow] += prob[len-1][nextPow]*dp[len-1][nextPow];
				}
				dp[len][pow] /= norm;
				if(norm == 0.0) {
					dp[len][pow] = 0.0;
				}
			} else {
				ld norm = 0.0;
				for(int nextPow = 1; nextPow < pow; nextPow++) {
					dp[len][pow] += prob[len-1][nextPow]*dp[len-1][nextPow];
					norm += prob[len-1][nextPow];
				}
				dp[len][pow] /= norm;
				if(norm == 0.0) {
					dp[len][pow] = 0.0;
				}
			}

			dp[len][pow] += (1 << pow);
		}
	}
	// cout << "=================================" << endl;
	// for(int i = 0; i <= n; i++) {
	// 	for(int j = 0; j < maxp; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	ld ans = 0;
	for(int pow = 1; pow < maxp; pow++) {
		ans += dp[n][pow]*prob[n][pow];
	}

	cout << fixed << setprecision(10) << ans << endl;
	
	return 0;
}