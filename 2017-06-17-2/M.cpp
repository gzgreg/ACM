#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	ll totKills = 0;
	vector<int> numKills;
	int nonzero = -1;
	for(int i = 0; i < n; i++) {
		int curr; cin >> curr;
		totKills += curr;
		numKills.push_back(curr);
		if(curr != 0) {
			nonzero = i;
		}
	}

	if(totKills > n-1) {
		cout << "NO" << endl;
		return 0;
	}
	vector<pii> kills;
	int alive = n - 1;
	while(nonzero > -1) {
		numKills[nonzero]--;
		kills.push_back({nonzero, alive});
		alive--;
		if(numKills[nonzero] == 0) {
			nonzero--;
		}
	}
	cout << "YES" << endl;
	for(pii curr : kills) {
		cout << curr.first + 1 << " " << curr.second  + 1 << endl;
	}
	
	return 0;
}