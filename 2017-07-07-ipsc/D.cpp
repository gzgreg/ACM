#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<bool> memo (2000000001, false);
int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	int t; cin >> t;
	set<int> vals;
	for(int a = 1; a < 2000000000; a++) {
		string s = to_string(a);
		vector<bool> unused(10, true);
		bool good = true;
		for(int i = 0; i < s.size(); i++) {
			if(!unused[s[i] - '0']) {
				good = false;
				break;
			}
			unused[s[i] - '0'] = false;
		}
		if(good) {
			vals.insert(a);
			memo[a] = true;
		}
	}
	for(int id = 0; id < t; id++) {
		int n; cin >> n;
		if(memo[n]) {
			cout << 1 << " " << n << endl;
			continue;
		}
		bool found = false;
		for(int i : vals) {
			if(memo[n-i]) {
				cout << "2 " << i << " " << n-i << endl;
				found = true;
				break;
			}
		}
		if(found) continue;
		auto it = vals.lower_bound(n);
		while(it != vals.begin()) {
			it--;
			auto it2 = vals.lower_bound(n - *it);
			while(it2 != vals.begin()) {
				it2--;
				if(memo[n-*it-*it2]) {
					cout << "3 " << *it2 << " " << n-*it-*it2 << " " << *it << endl;
					found = true;
					break;
				}
			}
			if(found) break;
		}
	}
	
	return 0;
}