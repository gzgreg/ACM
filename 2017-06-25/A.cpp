#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	int n; cin >> n;

	vector<vector<int>> lab(n, vector<int>(n));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> lab[i][j];
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(lab[i][j] != 1) {
				bool found = false;
				for(int k = 0; k < n; k++) {
					if(k == i) continue;
					for(int l = 0; l < n; l++) {
						if(l == j) continue;
						if(lab[k][j] + lab[i][l] == lab[i][j]) {
							found = true;
							break;
						}
					}
					if(found) break;
				}
				if(!found) {
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	
	cout << "Yes" << endl;
	return 0;
}