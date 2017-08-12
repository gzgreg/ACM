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

	int n, k; cin >> n >> k;
	vector<int> vals;
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; vals.push_back(cur);
	}

	int num = 0;
	int prev = 0;
	for(int i = 0; i < n; i++) {
		prev += vals[i];
		num += min(prev, 8);
		prev -= min(prev, 8);
		if(num >= k) {
			cout << i+1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	
	return 0;
}