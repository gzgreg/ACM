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
		vector<int> vals;
		for(int i = 0; i < 10; i++) {
			int cur; cin >> cur; vals.push_back(cur);
		}

		sort(vals.begin(), vals.end());
		cout << junk << " " << vals[7] << endl;
	}
	
	return 0;
}