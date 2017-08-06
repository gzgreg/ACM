#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	char dir1, dir2; cin >> dir1 >> dir2;
	int n; cin >> n;

	map<char, int> remap;
	remap['v'] = 0;
	remap['<'] = 1;
	remap['^'] = 2;
	remap['>'] = 3;

	if((remap[dir1] + n) % 4 == remap[dir2]) {
		if((remap[dir1] - n + (int) 2e9) % 4 == remap[dir2]){
			cout << "undefined" << endl;
		} else {
			cout << "cw" << endl;
		}
	} else if((remap[dir1] - n + (int) 2e9) % 4 == remap[dir2]){
		cout << "ccw" << endl;
	} else {
		cout << "undefined" << endl;
	}
	
	return 0;
}