#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pii;
typedef vector<long long> vi;

#define endl '\n'

#define MOD 1000000007

int main(){
	freopen("monotonic.in", "r", stdin);
	freopen("monotonic.out", "w", stdout);

	long long n, k; cin >> n >> k;
	vector<bool> dir (n+1, false);
	long long endId = 0;
	for(long long i = 0; i < k; i++){
		long long curr; cin >> curr;
		endId += curr;
		dir[endId] = true;
	}

	long long memo[n][n]; memset(memo, -1, sizeof memo);

	for(long long i = 0; i < n; i++){
		memo[0][i] = 1;
	}

	for(long long i = 1; i < n; i++){
		for(long long j = 0; j < n-i; j++){
			long long val = 0;
			if(!dir[i]){
				for(long long k = j+1; k < n; k++){
					if(memo[i-1][k] == -1) continue;
					val += memo[i-1][k];
					val %= MOD;
				}
			} else {
				for(long long k = 0; k <= j; k++){
					if(memo[i-1][k] == -1) continue;
					val += memo[i-1][k];
					val %= MOD;
				}
			}
			memo[i][j] = val;
		}
	}

	cout << memo[n-1][0] << endl;

	// for(int i = 0; i < n; i++){
	// 	cout << dir[i] << " ";
	// }
	// cout << endl;
	// for(long long i = 0; i < n; i++){
	// 	for(long long j = 0; j < n; j++){
	// 		cout << memo[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	return 0;
}