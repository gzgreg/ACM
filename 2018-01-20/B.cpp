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

	int n, m; cin >> n >> m;

	vector<int> cnt;

	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; cnt.push_back(cur);
	}

	if(m < n) {
		cout << "VANCOUVER" << endl;
		return 0;
	}

	multiset<int> vals;
	for(int i = 0; i < n; i++) {
		vals.insert(cnt[i]);
	}

	if(vals.count(0)) {
		cout << "VANCOUVER" << endl;
		return 0;
	}

	for(int i = n; i > 0; i--) {
		if(vals.lower_bound(i) == vals.end()) {
			cout << "UNCERTAIN" << endl;
			return 0;
		}
		vals.erase(vals.lower_bound(i));
	}

	cout << "BROOKLYN" << endl;
	
	return 0;
}