#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<set<int>> adj;
set<int> vis;
double dfs(int node, int dist) {
	double ret = 0;
	int numChild = 0;
	vis.insert(node);
	for(int i : adj[node]) {
		if(!vis.count(i)) {
			ret += dfs(i, dist + 1);
			numChild++;
		}
	}
	if(numChild == 0) {
		return dist;
	}
	ret /= numChild;
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	adj = vector<set<int>> (n);
	for(int i = 0; i < n-1; i++) {
		int ui, vi; cin >> ui >> vi;
		ui--; vi--;
	    adj[ui].insert(vi);
		adj[vi].insert(ui);
	}

	double ans = dfs(0, 0);

	cout << fixed << setprecision(10) << ans << endl;
	
	return 0;
}