#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n, k; cin >> n >> k;

	tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> vals;
	for(int i = 0; i < n; i++) {
		vals.insert(i);
	}
	vector<int> ans;
	for(int i = 0; i < n; i++) {
		int nxt = min(k, n - i - 1);

		auto res = *vals.find_by_order(nxt);
		ans.push_back(res);
		vals.erase(res);
		k -= nxt;
	}

	for(int i : ans) {
		cout << i+1 << " ";
	}
	cout << endl;

	return 0;
}