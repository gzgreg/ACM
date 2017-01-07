#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;

	int currLoc = 0;

	while(n--) {
		int dist; string dir;
		cin >> dist >> dir;

		if(currLoc == 0) {
			if(dir != "South") {
				cout << "NO" << endl;
				return 0;
			}
		} else if (currLoc == 20000) {
			if(dir != "North") {
				cout << "NO" << endl;
				return 0;
			}
		}

		if(dir == "South") {
			currLoc += dist;
			if(currLoc > 20000) {
				cout << "NO" << endl;
				return 0;
			}
		} else if (dir == "North") {
			currLoc -= dist;
			if(currLoc < 0) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	
	cout << (currLoc == 0 ? "YES" : "NO") << endl;

	return 0;
}