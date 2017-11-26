#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;

	vector<int> sz(2001);
	for(int i = 0; i < N; i++) {
		int cur; cin >> cur; sz[cur]++;
	}
	int maxLen = 0;
	int ans = 0;
	for(int i = 2; i <= 4000; i++) {
		int curLen = 0;
		for(int j = max(1,i - 2000); j <= min(i, 2000); j++) {
			if(j == i-j) {
				curLen += sz[j];
			} else {
				curLen += min(sz[j], sz[i-j]);
			}
		}
		if(curLen > maxLen) {
			ans = 1;
			maxLen = curLen;
		} else if (curLen == maxLen) {
			ans++;
		}
	}

	cout << maxLen/2 << " " << ans << endl;
	
	return 0;
}