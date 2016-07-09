#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int inp[n][n];
		memset(inp,0,sizeof inp);
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				char c; cin >> c;
				if (c == 'F') inp[i][j] = 1;
			}
		}
		int ans[n][n];
		int mx = 0;
		for (int i=n-1;i>=0;i--) {
			for (int j=n-1;j>=0; j--) {
				if (inp[i][j] == 1) {
					ans[i][j] = 0;
				} else {
					if (i == n-1 || j == n-1) {
						ans[i][j] = 1;
					} else {
						ans[i][j] = min(min(ans[i][j+1],ans[i+1][j+1]),ans[i+1][j]) +1;
					}
				}
				mx = max(mx,ans[i][j]);
			}
		}
		cout << mx << endl;
	}
	return 0;
}