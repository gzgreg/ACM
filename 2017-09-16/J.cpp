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

	int n, p; cin >> n >> p;

	list<int> vals;
	auto it = vals.begin();
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; vals.push_back(cur);
		if(i < p) it++;
	}
	int q; cin >> q;
	while(q--) {
		string s; cin >> s;
		if(s == "print") {
			cout << *it << endl;
		} else if (s == "moveLeft") {
			if(it != vals.begin()) it--;
		} else if (s == "moveRight") {
			if(it != --vals.end()) it++;
		} else if (s == "insertLeft") {
			int x; cin >> x;
			vals.insert(it, x);
		} else if (s == "insertRight") {
			int x; cin >> x;
			it++;
			vals.insert(it, x);
			it--; it--;
		}
	}

	
	return 0;
}