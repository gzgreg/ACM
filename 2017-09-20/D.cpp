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

	int n; cin >> n;

	unordered_map<string, vector<int>> vals;
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		for(int k = 0; k < 9; k++) {
			string cur; cur.push_back(s[k]); 
			if(vals[cur].size() == 0 || vals[cur].back() != i) vals[cur].push_back(i);
			for(int j = 1; j < 9 - k; j++) {
				cur.push_back(s[k+j]);
				if(vals[cur].size() == 0 || vals[cur].back() != i) vals[cur].push_back(i);
			}
		}
	}

	vector<string> ans(n, "asdfasdfasdf");

	for(auto cur : vals) {
		if(cur.second.size() == 1) {
			int idx = cur.second[0];
			if(ans[idx].size() > cur.first.size()) {
				ans[idx] = cur.first;
			} 
		}
	}

	for(int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}
	
	return 0;
}