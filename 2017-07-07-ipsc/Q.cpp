#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	int t; cin >> t;

	for(int id = 0; id < t; id++) {
		int n, e; cin >> n >> e;
		set<int> unseen;
		vector<int> evts(e+n, 0);
		for(int i = 1; i <= n; i++) {
			unseen.insert(i);
			evts[i-1] = n-i+1;
		}
		for(int i = 0; i < e; i++) {
			cin >> evts[i+n];
		}

		for(int i = 0; i < evts.size(); i++) {
			unseen.erase(evts[evts.size() - i - 1]);
			if(unseen.size() == 1) {
				cout << *(unseen.begin()) << endl;
				break;
			}
		}
	}
	
	return 0;
}