#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll dp[100001][20];
ll dist[100001][20];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, w; cin >> n >> m >> w;
	vector<pair<ll, ll>> par(n, {-1, -1});
	for(int i = 0; i < n-1; i++) {
		ll a, b, l;
		cin >> a >> b >> l;
		a--; b--;
		par[b] = {a, l};
	}
	memset(dp, -1, sizeof dp);
	memset(dist, -1, sizeof dist);

	for(int i = 0; i < n; i++) {
		dp[i][0] = par[i].first;
		dist[i][0] = par[i].second;
	}

	for(int i = 1; i < 20; i++) {
		for(int j = 0; j < n; j++) {
			if(dist[j][i-1] != -1) {
				dp[j][i] = dp[dp[j][i-1]][i-1];
				if(dp[j][i] != -1) {
					dist[j][i] = dist[j][i-1] + dist[dp[j][i-1]][i-1];
				}
			}
		}
	}

	for(int i = 0; i < n; i++) {
		int curNode = i;
		ll curDist = 0;
		for(int j = 19; j >= 0; j--) {
			if(dp[curNode][j] != -1) {
				if((curDist + dist[curNode][j]) < w) {
					curDist += dist[curNode][j];
					curNode = dp[curNode][j];
				} else if ((curDist + dist[curNode][j]) == w) {
					cout << "PEACEFUL BLISS" << endl;
					return 0;
				}
			} 
		}
	}

	cout << "STRESS" << endl;
	
	return 0;
}