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

	int k; cin >> k;
	string n; cin >> n;

	int curSum = 0;
	map<int, int> nums;
	for(int i = 0; i < n.size(); i++) {
		curSum += n[i] - '0';
		nums[n[i] - '0']++;
	}

	int ans = 0;
	while(curSum < k) {
		for(pii cur : nums) {
			if(cur.second == 0) continue;
			nums[cur.first]--;
			curSum += 9 - cur.first;
			ans++;
			break;
		}
	}
	
	cout << ans << endl;

	return 0;
}