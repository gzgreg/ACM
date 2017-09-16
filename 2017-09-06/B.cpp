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
	
	int P; cin >> P;
	while(P--) {
		int junk; cin >> junk;

		int M; cin >> M;
		vector<int> vals;
		ll tot = 0;
		unordered_set<int> cumsums;
		for(int i = 0; i < M; i++) {
			int cur; cin >> cur; vals.push_back(cur);
			tot += cur;
			cumsums.insert(tot);
		}
		int curVal = 0;
		for(int i = 0; i < M; i++) {
			curVal += vals[i];
			if(tot % curVal != 0) continue;
			bool good = true;
			for(int j = curVal; j <= tot; j += curVal) {
				if(!cumsums.count(j)) {
					good = false;
					break;
				}
			}
			if(good) {
				cout << junk << " " << curVal << endl;
				break;
			}
		}




	}
	
	return 0;
}