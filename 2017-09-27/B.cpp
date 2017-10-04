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

	int T; cin >> T;
	while(T--) {
			int n, m; cin >> n >> m;

		vector<int> vals;
		int start;
		for(int i = 0; i < n; i++) {
			int cur; cin >> cur; vals.push_back(cur);
			if(cur != -1) {
				start = i;
			}
		}

		for(int i = start; i < n; i++) {
			if(vals[i] == -1) {
				vals[i] = (vals[i-1] + 1) % m;
			}
		}

		for(int i = start; i >= 0; i--) {
			if(vals[i] == -1) {
				vals[i] = (vals[i+1] + m - 1) % m;
			}
		}

		for(int i : vals) {
			cout << i << " ";
		}
		cout << endl;
	}

	
	return 0;
}