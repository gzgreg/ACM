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

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> rank(n);
		map<int, int> numAhead;
		for(int i = 0; i < n; i++) {
			cin >> rank[i];
			numAhead[rank[i]] = i;
		}
		int m; cin >> m;
		map<int, int> oldNumAhead(numAhead);
		for(int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			if(oldNumAhead[a] > oldNumAhead[b]) {
				numAhead[a]--;
				numAhead[b]++;
			} else {
				numAhead[a]++;
				numAhead[b]--;
			}
		}
		vector<int> newRank(n, -1);
		bool good = true;
		for(pii curr : numAhead) {
			if(newRank[curr.second] != -1) {
				good = false;
				break;
			}
			newRank[curr.second] = curr.first;
		}
		if(good) {
			for(int i : newRank) {
				cout << i << " ";
			}
			cout << endl;
		} else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	
	return 0;
}