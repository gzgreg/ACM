#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	int n, x; cin >> n >> x;

	map<int, vector<vector<int>>> vals;
	for(int i = 0; i < n; i++) {
		int li, ri, ci; cin >> li >> ri >> ci;
		vals[ri-li+1].push_back({li, ri, ci});
	}

	int bestCost = 2e9 + 1;

	for(int i = 0; i <= x/2; i++) {
		vector<vector<int>> val1 = vals[i];
		vector<vector<int>> val2 = vals[x-i];
		if(val1.size() == 0 || val2.size() == 0) continue;
		sort(val1.begin(), val1.end());
		sort(val2.begin(), val2.end());
		multiset<int> goodCosts;
		for(vector<int> i : val2) {
			goodCosts.insert(i[2]);
		}
		int r = 0;
		for(int l = 0; l < val1.size(); l++) {
			while(r < val2.size() && val2[r][0] <= val1[l][1]) {
				goodCosts.erase(goodCosts.find(val2[r][2]));
				r++;
			}
			if(r == val2.size()) break;
			bestCost = min(bestCost, val1[l][2] + *(goodCosts.begin()));
		}
		goodCosts.clear();
		for(vector<int> i : val2) {
			goodCosts.insert(i[2]);
		}
		r = val2.size() - 1;
		for(int l = val1.size() - 1; l >= 0; l--) {
			while(r >= 0 && val2[r][1] >= val1[l][0]) {
				goodCosts.erase(goodCosts.find(val2[r][2]));
				r--;
			}
			if(r < 0) break;
			bestCost = min(bestCost, val1[l][2] + *(goodCosts.begin()));
		}
	}
	if(bestCost == 2e9+1) bestCost = -1;

	cout << bestCost << endl;

	return 0;
}