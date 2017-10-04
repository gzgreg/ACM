#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000000007

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		vector<int> vals(n);
		int maxVal = 0;
		int nextMaxVal = 0;
		bool multiple = false;
		set<int> valSet;
		map<int, int> counts;
		for(int i = 0; i < n; i++) {
			int cur; cin >> cur; vals[i] = cur;
			if(cur > maxVal && cur < MOD){
				maxVal = cur;
				multiple = false;
			} else if (cur == maxVal) {
				multiple = true;
			}
			counts[cur]++;
			valSet.insert(cur);
		}
		nextMaxVal = *(--(--(valSet.end())));
		vector<int> ans(n);
		for(int i = 0; i < n; i++) {
			auto it = valSet.lower_bound(MOD - vals[i]);

			if(vals[i] == maxVal) {
				if(multiple) {
					ans[i] = (maxVal * 2) % MOD;
				} else {
					ans[i] = (maxVal + nextMaxVal) % MOD;
				}
			} else {
				ans[i] = (maxVal + vals[i]) % MOD;
			}

			if(it == valSet.end() || it == valSet.begin()) {

			} else {
				it--;
				if(*it == vals[i] && counts[vals[i]] == 1) {
					if(it == valSet.begin()) continue;
					it--;
				}
				ans[i] = max(ans[i], (vals[i] + *it) % MOD);
			}
		}
		for(int i : ans) {
			cout << i << " ";
		}
		cout << endl;
	}
	
	return 0;
}