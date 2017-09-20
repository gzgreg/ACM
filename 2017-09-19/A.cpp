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

	int n, x; cin >> n >> x;

	set<int> vals;
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; vals.insert(cur);
	}
	int ans = 0;
	for(int i = 0; i < x; i++) {
		if(!vals.count(i)) {
			ans++;
		}
	}

	if(vals.count(x)) ans++;
	
	cout << ans;

	return 0;
}