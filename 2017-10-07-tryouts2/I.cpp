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

	int n; cin >> n;
	while(n--) {
		int g; cin >> g;
		vector<int> vals;
		for(int i = 0; i < g; i++) {
			int cur; cin >> cur; vals.push_back(cur);
		}

		for(int i = 1; i < g-1; i++) {
			if(vals[i] > vals[i+1] && vals[i+1] > vals[i-1]) {
				cout << i+1 << endl;
				break;
			}
			if(vals[i] < vals[i-1] && vals[i+1] > vals[i-1]) {
				cout << i+1 << endl;
				break;
 			}
		}
	}
	
	return 0;
}