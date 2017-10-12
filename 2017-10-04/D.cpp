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

	string s; cin >> s;

	vector<int> cumsum;
	cumsum.push_back(0);
	for(int i = 0; i < s.size(); i++) {
		cumsum.push_back(cumsum.back());
		if(s[i] == '(') {
			cumsum.back()++;
		} else {
			cumsum.back()--;
		}
	}
	map<pii, int> minB, maxB;
	for(int i = 0; i < s.size(); i++) {
		int curMin = 0;
		int curMax = 0;
		int curVal = 0;
		for(int j = i; j < s.size(); j++) {
			curVal += (s[j] == '(' ? 1 : -1);
			curMin = min(curMin, curVal);
			curMax = max(curMax, curVal);
			minB[{i, j}] = curMin;
			maxB[{i, j}] = curMax;
		}
	}

	for(int i = 0; i < s.size(); i++) {
		for(int j = i; j < s.size(); j++) {
			int rise = cumsum[j+1] - cumsum[i];
			if(cumsum.back() == rise * 2) {
				cout << i << " " << j << endl;
				cout << maxB[{i, j}] << " " << cumsum[i] <<  endl;
				cout << minB[{0, i-1}] - rise << " " << minB[{j+1, s.size() - 1}] << endl;
				if(minB[{i, j}] + rise <= cumsum[i]
					&& minB[{0, i-1}] - rise >= minB[{j+1, s.size() - 1}]) {
					cout << "possible" << endl;
					return 0;
				}
			}
		}
	}

	cout << "impossible" << endl;
	
	return 0;
}