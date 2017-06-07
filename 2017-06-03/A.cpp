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
		int ans = 0;
		for(int i = 0; i < 20; i++) {
			int curr; cin >> curr; nums.push_back(curr);
			for(int j = 0; j < i; j++) {
				if(nums[i] < nums[j]) {
					ans++;
				}
			}
		}
		cout << K << " " << ans << endl;

	}
	
	return 0;
}