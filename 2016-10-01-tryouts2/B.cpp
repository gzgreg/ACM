#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;

	while(T--) {
		int n, m; cin >> n >> m;
		vector<int> nums;
		vector<int> neg;
		for(int i = 0; i < n; i++) {
			int ai; cin >> ai;
			if(ai > 0) {
				nums.push_back(ai);
			} else {
				neg.push_back(ai);
			}
		}

		sort(nums.begin(), nums.end());
		sort(neg.begin(), neg.end());
		int total = 0;
		total += nums[0];
		total += nums[1];
		for(int i = 2; i < nums.size(); i++) {
			total += nums[i] * 2;
		}
		if(neg.size() >= 1 && -neg[neg.size() - 1] < nums[1]) {
			total += nums[1];
			total += neg[neg.size() - 1];
		}
		if(neg.size() >= 2 && -neg[neg.size() - 2] < nums[0]) {
			total += nums[0];
			total += neg[neg.size() - 2];
		}
		cout << total << endl;
	}
	
	return 0;
}