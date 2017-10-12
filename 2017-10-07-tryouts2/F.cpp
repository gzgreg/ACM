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

	int x, y; cin >> x >> y;
	int n; cin >> n;
	vector<int> ins;
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		if(s[0] == 'F') {
			ins.push_back(0);
		} else if (s[0] == 'L') {
			ins.push_back(1);
		} else {
			ins.push_back(2);
		}
	}

	for(int i = 0; i < n; i++) {
		int oldVal = ins[i];
		for(int j = 0; j < 3; j++) {
			if(ins[i] == j) continue;

			ins[i] = j;
			complex<int> curLoc = {0, 0};
			complex<int> dir = {0, 1};
			for(int k = 0; k < n; k++) {
				if(ins[k] == 0) {
					curLoc += dir;
				} else if (ins[k] == 1) {
					dir = dir * complex<int>(0, 1);
				} else {
					dir = dir * complex<int>(0, -1); 
				}
			}
			if(curLoc.real() == x && curLoc.imag() == y) {
				cout << i+1 << endl;
				string s;
				if(j == 0) {
					s = "Forward";
				} else if (j == 1) {
					s = "Left";
				} else {
					s = "Right";
				}
				cout << s << endl;
				return 0;
			}

			ins[i] = oldVal;
		}
	}
	
	return 0;
}