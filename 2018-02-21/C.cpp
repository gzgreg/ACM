#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

multiset<int> vals;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	auto it = vals.begin();
	while(cin >> s) {
		if(s[0] == '#') {
			auto cur = *it;
			auto prevIt = it;
			if(vals.size() % 2 == 0) {
				it--;
			} else {
				it++;
			}
			vals.erase(prevIt);
			cout << cur << endl;
		} else {
			int cur = stoi(s);
			vals.insert(cur);
			if(vals.size() == 1) {
				it = vals.begin();
			} else {
				if(cur >= *it) {
					if (vals.size() % 2 == 0) {
						it++;
					}
				}
				if(cur < *it && vals.size() % 2 == 1) {
					it--;
				}
			}
		}
	}
	
	return 0;
}