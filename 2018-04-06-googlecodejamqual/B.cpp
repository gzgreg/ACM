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
	for(int id = 1; id <= T; id++) {
		cout << "Case #" << id << ": ";
		int N; cin >> N;
		vector<int> vals;
		for(int i = 0; i < N; i++) {
			int cur; cin >> cur; vals.push_back(cur);
		}

		vector<int> sortedVals(vals);
		sort(sortedVals.begin(), sortedVals.end());

		vector<int> evenVals, oddVals;
		for(int i = 0; i < N; i++) {
			if(i%2) oddVals.push_back(vals[i]);
			else evenVals.push_back(vals[i]);
		}
		sort(oddVals.begin(), oddVals.end());
		sort(evenVals.begin(), evenVals.end());
		bool good = true;
		for(int i = 0; i < N; i++) {
			if(i % 2) {
				if(oddVals[i/2] != sortedVals[i]) {
					cout << i << endl;
					good = false;
					break;
				}
			} else {
				if(evenVals[i/2] != sortedVals[i]) {
					cout << i << endl;
					good = false;
					break;
				}
			}
		}

		if(good) cout << "OK" << endl;
	}
	
	return 0;
}