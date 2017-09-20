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

	string s; cin >> s;
	int depth = 0;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(') {
			depth++;
		} else {
			depth--;
			if(depth < 0) {
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
		}
	}

	for(int i = 0; i < depth; i++) {
		s.push_back(')');
	}

	cout << s << endl;
	
	return 0;
}