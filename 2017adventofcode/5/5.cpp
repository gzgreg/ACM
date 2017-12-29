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

	int num;
	vector<int> nums;
	while(cin >> num) {
		nums.push_back(num);
	}
	int idx = 0;
	int ans = 0;
	while(idx >= 0 && idx < nums.size()) {
		ans++;
		if(nums[idx] >= 3) {
			nums[idx]--;

			idx += nums[idx] + 1;
		} else {
			nums[idx]++;	
			idx += nums[idx] - 1;
		}
	}

	cout << ans << endl;
	
	return 0;
}