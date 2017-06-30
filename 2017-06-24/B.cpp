#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000000007

int memo[61][11801][201];
int N, fullmarks;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> N >> fullmarks;
	for(int k = 0; k < 201; k++) {
		int cumsum[11802]; cumsum[0] = 0; 
		for(int i = 0; i < 61; i++) {
			for(int j = 0; j < 11801; j++) {
				if(i == 0 && j == 0) {
					memo[i][j][k] = 1;
				} else if(i != 0){
					if(j > i*k){
						break;
					}
					memo[i][j][k] = cumsum[j+1] - cumsum[max(j-k, 0)];
					memo[i][j][k] += MOD;
					memo[i][j][k] %= MOD;
				}
			}

			for(int j = 0; j < 11801; j++) {
				if(j > (i+1)*k + 10){
					break;
				}
				cumsum[j+1] = cumsum[j] + memo[i][j][k];
				cumsum[j+1] %= MOD;
			}
		}
	}

	while(N != 0) {
		ll ans = 0;
		for(int i = 0; i <= fullmarks; i++) {
			ans += memo[N-1][i * (N-1)][fullmarks] * (ll) N;
			ans %= MOD;
		}
		cout << ans << endl;

		cin >> N >> fullmarks;
	}
	
	return 0;
}