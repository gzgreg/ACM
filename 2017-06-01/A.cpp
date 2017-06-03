#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	vector<vector<int>> vals (4, vector<int> (4, 0));

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			cin >> vals[i][j];
		}
	}

	for(int i = 0; i < 4; i++) {
		if(vals[i][3]) {
			if(vals[(i+1) % 4][0]
				|| vals[(i+2) % 4][1]
				|| vals[(i+3) % 4][2]) {
				cout << "YES" << endl;
				return 0;
			}
			for(int j = 0; j < 3; j++) {
				if(vals[i][j]) {
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}
	cout << "NO" << endl;
	
	return 0;
}