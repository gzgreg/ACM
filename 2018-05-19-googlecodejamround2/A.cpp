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

	int T; cin >> T;

	for(int id = 1; id <= T; id++) {
		cout << "Case #" << id << ": ";

		int C; cin >> C;
		vector<int> B;
		int total = 0;
		for(int i = 0; i < C; i++) {
			int bi; cin >> bi; B.push_back(bi); total += bi;
		}
		if(total != C || B[0] == 0 || B.back() == 0) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}

		vector<string> ans (C, string(C, '.'));

		int curIdx = 0;
		for(int i = 0; i < C; i++) {
			while(curIdx != C && B[curIdx] == 0) {
				curIdx++;
			}
			if(curIdx == C) break;
			if(curIdx < i) {
				for(int j = i; j > curIdx; j--) {
					ans[i-j][j] = '/';
				}
			} else if(curIdx > i) {
				for(int j = i; j < curIdx; j++) {
					ans[j-i][j] = '\\';
				}
			}
			B[curIdx]--;
		}
		int tot = 0;
		string cmp(C, '.');
		for(auto cur : ans) {
			tot++;
			if(cur == cmp) break;
		}
		cout << tot << endl;
		for(int i = 0; i < tot; i++) {
			cout << ans[i] << endl;
		}
	}
	
	return 0;
}