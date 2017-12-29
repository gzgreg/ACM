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

	vector<int> vals;

	for(int i = 0; i < 16; i++) {
		int cur; cin >> cur; vals.push_back(cur);
	}

	set<vector<int>> seen;
	seen.insert(vals);
	int ans = 1;

	while(true) {
		int maxIdx = 0;
		int maxVal = 0;
		for(int i = 0; i < 16; i++) {
			if(maxVal < vals[i]) {
				maxVal = vals[i];
				maxIdx = i;
			}
		}
		vals[maxIdx] = 0;
		maxIdx++;
		maxIdx %= 16;
		while(maxVal > 0) {
			vals[maxIdx]++;
			maxIdx++;
			maxIdx %= 16;
			maxVal--;
		}
		if(seen.count(vals)) {
			cout << ans << endl;
			for(int i = 0; i < vals.size(); i++) {
				cout << vals[i] << " ";
			}
			cout << endl;
			break;
		}
		ans++;
		seen.insert(vals);
	}
	
	return 0;
}