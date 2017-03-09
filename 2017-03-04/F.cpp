#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	
	map<int, vector<pii>> nums;

	set<int, greater<int>> weights;
	vector<int> rack1, rack2;
	int n; cin >> n;

	for(int i = 0; i < n; i++) {
		int curr; cin >> curr; rack1.push_back(curr);
		nums[curr].push_back({1, i});
		weights.insert(curr);
	}
	for(int i = 0; i < n; i++) {
		int curr; cin >> curr; rack2.push_back(curr);
		nums[curr].push_back({2, i});
		weights.insert(curr);
	}

	int minMove = 0;

	for(int curr : weights) {
		if(minMove >= curr) break;

		vector<pii> locs = nums[curr];
		if(locs[0].first != locs[1].first) {
			minMove = curr;
			break;
		} else {
			for(int i = locs[0].second + 1; i < locs[1].second; i++) {
				if(locs[0].first == 1) {
					if(rack1[i] > curr) {
						cout << curr << endl;
						return 0;
					}
					minMove = max(minMove, rack1[i]);
				} else {
					if(rack2[i] > curr) {
						cout << curr << endl;
						return 0;
					}
					minMove = max(minMove, rack2[i]);
				}
			}
		}
	}

	cout << minMove << endl;

	return 0;
}