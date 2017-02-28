#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;
	while(n != 0) {
		vector<int> nums;
		for(int i = 0; i < n; i++) {
			int curr; cin >> curr; nums.push_back(curr);
		}
		int totalCost = 0;

		while(nums.size() > 2) {
			int minCost = 10000;
			int idx = 0;
			for(int i = 0; i < nums.size(); i++) {
				if(__gcd(nums[(i + 1) % nums.size()],
						nums[(i + nums.size() - 1) % nums.size()]) < minCost) {
					minCost = __gcd(nums[(i + 1) % nums.size()],
						nums[(i + nums.size() - 1) % nums.size()]);
					idx = i;
				}
			}
			nums.erase(nums.begin() + idx);
			totalCost += minCost;
		}
		totalCost += __gcd(nums[0], nums[1]);
		cout << totalCost << endl;
		cin >> n;
	}
	
	return 0;
}