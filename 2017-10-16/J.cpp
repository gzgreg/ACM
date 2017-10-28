#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;

vector<int> sizes;

ld memo[51][51][51];

ld factorial[51];

ld nCr(int n, int r) {
	return factorial[n] / factorial[r] / factorial[n-r];
}

ld dp(int roomId, int people, int biggest) {
	if(roomId == m) {
		if(people > 0) {
			return 0;
		} else {
			return 1;
		}
	} else if (memo[roomId][people][biggest] > -0.5) {
		return memo[roomId][people][biggest];
	}

	ld ans = 0;
	int maxPeople = biggest * sizes[roomId];
	for(int i = 0; i <= min(people, maxPeople); i++) {
		ans += nCr(people, i) * dp(roomId + 1, people - i, biggest);
	}
	return memo[roomId][people][biggest] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	sizes.resize(m);
	for(int i = 0; i < m; i++) {
		cin >> sizes[i];
	}

	for(int i = 0; i < 51; i++) {
		for(int j = 0; j < 51; j++) {
			for(int k = 0; k < 51; k++) {
				memo[i][j][k] = -1;
			}
		}
	}
	factorial[0] = 1;
	for(int i = 1; i <= 50; i++) {
		factorial[i] = factorial[i-1] * i;
	}

	for(int i = 1; i <= n; i++) {
		dp(0, n, i);
	}
	
	memo[0][n][0] = 0;
	ld ans = 0;

	for(int i = 1; i <= n; i++) {
		ans += (memo[0][n][i] - memo[0][n][i-1]) * i;
	}
	for(int i = 0; i < n; i++) {
		ans /= m;
	}

	cout << fixed << setprecision(10) << ans << endl;
	
	return 0;
}