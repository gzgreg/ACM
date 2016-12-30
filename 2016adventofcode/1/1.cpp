#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	complex<int> loc(0, 0);
	complex<int> dir(0, 1);

	set<pair<int, int>> visited;

	string s;
	while(cin >> s) {
		if(s[0] == 'L') {
			dir = dir * complex<int>(0, 1);
		} else {
			dir = dir * complex<int>(0, -1);
		}
		int dist = atoi(s.substr(1, s.size() - 2).c_str());
		for(int i = 1; i <= dist; i++) {
			if(visited.count({loc.real(), loc.imag()})) {
				cout << abs(loc.real()) + abs(loc.imag()) << endl;
				return 0;
			}
			visited.insert({loc.real(), loc.imag()});
			loc += dir;
		}
	}

	cout << abs(loc.real()) + abs(loc.imag()) << endl;
	
	return 0;
}