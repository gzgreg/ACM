#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	for(int id = 1; id <= T; id++) {
		int N, P; cin >> N >> P;
		cout << "Case #" << id << ": ";
		vector<int> nums;
		for(int i = 0; i < N; i++) {
			int curr; cin >> curr; nums.push_back(curr);
		}

		if(P == 2) {
			int ans = 0, tmpAns = 0;
			for(int i : nums) {
				if(i % 2 == 0) {
					ans++;
				} else {
					tmpAns++;
				}
			}

			cout << ans + ((tmpAns + 1) / 2) << endl;
		} else if (P == 3) {
			int ans = 0;
			vector<int> newNums1, newNums2;
			for(int num : nums) {
				if(num % 3 == 0) {
					ans++;
				} else if(num % 3 == 1) {
					newNums1.push_back(num);
				} else {
					newNums2.push_back(num);
				}
			}

			ans += min(newNums1.size(), newNums2.size());
			if(newNums1.size() > newNums2.size()) {
				ans += 1 + (newNums1.size() - newNums2.size() -1) / 3;
			} else if (newNums2.size() > newNums1.size()) {
				ans += 1 + (newNums2.size() - newNums1.size() - 1) / 3;
			}
			cout << ans << endl;
		} else if (P == 4) {
			vector<int> mods = {0, 0, 0, 0};
			for(int i : nums) {
				mods[i % 4]++;
			}
			int ans = mods[0];
			ans += mods[2] / 2; mods[2] = mods[2] % 2;
			if(mods[2] != 0) {
				if(mods[1] > mods[3]) {
					if(mods[1] >= 2) {
						mods[1] -= 2;
						ans++;
					}
				} else {
					if(mods[3] >= 2) {
						mods[3] -= 2;
						ans++;
					}
				}
			}
			int tmp = min(mods[1], mods[3]);
			ans += tmp; mods[1] -= tmp; mods[3] -= tmp;
			if(mods[1] > 0) {
				ans += 1 + (mods[1] -1) / 3;
			} else if (mods[3] > 0) {
				ans += 1 + (mods[1] -1) / 3;
			}
			cout << ans << endl;
		}
	}
	
	return 0;
}