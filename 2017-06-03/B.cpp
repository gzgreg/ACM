#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int P; cin >> P;
	while(P--) {
		int K; cin >> K;

		vector<int> nums;
		for(int i = 0; i < 12; i++) {
			int curr; cin >> curr; nums.push_back(curr);
		}
		int ans = 0;
		for(int i = 1; i < 11; i++) {
			for(int j = i+1; j <= 11; j++) {
				int minNum = 1e9;
				for(int k = i; k < j; k++) {
					minNum = min(minNum, nums[k]);
				}
				if(minNum > nums[i-1] && minNum > nums[j]) {
					ans++;
				}
			}
		}
		cout << K << " " << ans << endl;
	}
	
	return 0;
}