#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<int, vector<int>> adj;
set<int> seen;

int dfs(int cur) {
	if(seen.count(cur)) return 0;
	seen.insert(cur);
	int ans = 1;
	for(auto val : adj[cur]) {
		ans += dfs(val);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;

	while(getline(cin, s)) {
		istringstream ss(s);
		int i; ss >> i;
		ss >> s;
		int val; char junk;
		while(ss >> val) {
			adj[i].push_back(val);
			ss >> junk;
		}
	}
	
	int ans = 0;
	for(auto cur : adj) {
		if(dfs(cur.first) > 0) ans++;
	}
	cout << ans << endl;
	
	return 0;
}