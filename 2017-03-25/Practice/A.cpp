#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;

	while(T--) {
		int N; cin >> N;
		vector<int> nums;

		for(int i = 0; i < N; i++) {
			int curr; cin >> curr; nums.push_back(curr);
		}

		int parity = nums[0]%2 + nums[1]%2 + nums[2]%2;
		if(parity < 2) {
			for(int i = 0; i < N; i++) {
				if(nums[i] % 2) {
					cout << i + 1 << endl;
					break;
				}
			}
		} else {
			for(int i = 0; i < N; i++) {
				if(!(nums[i] % 2)) {
					cout << i + 1 << endl;
					break;
				}
			}
		}
	}
	
	return 0;
}