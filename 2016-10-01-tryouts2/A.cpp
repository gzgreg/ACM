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
		vector<int> idx (m+1, 0);
		for(int i = 1; i <= m; i += 2) {
			idx[i] = 100000000;
		}
		map<int, pii> nums;
		int currNum = 20000000;
		for(int i = 0; i < n; i++) {
			int num; cin >> num;
			if(currNum != num) {
				nums[currNum].second = i - 1;
				nums[num] = {i, 0};
				currNum = num;
			}
		}

		nums[currNum].second = n - 1;
		for(int i = 1; i <= m; i++) {
			if(nums[i - 1].first > nums[i].first) {
				idx[i] = nums[i].first;
			} else {
				idx[i] = nums[i].second;
			}
		}
		if(nums.size() >= 2) {
			if(nums[2].first > nums[1].first) {
				idx[1] = nums[1].first;
			} else {
				idx[1] = nums[1].second;
			}
		}
		
		int ans = 0;
		for(int i = 2; i <= m; i++) {
			ans += abs(idx[i] - idx[i-1]);
		}
		cout << ans << endl;
	}

	return 0;
}