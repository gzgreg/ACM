#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pii;
typedef vector<long long> vi;

#define endl '\n'
#define MOD 1000000009

vector<int> factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

int main(){
	ios::sync_with_stdio(0);

	long long t; cin >> t;
	while(t--) {
		long long n; cin >> n;
		vector<long long> perm;
		set<long long> visit;
		for(long long i = 0; i < n; i++) {
			long long curr; cin >> curr; perm.push_back(curr); visit.insert(i);
		}

		multiset<long long> nums; //cycle lengths
		while(!visit.empty()) {
			long long idx = *(visit.begin());
			long long num = 0;
			while(visit.find(idx) != visit.end()) {
				num++;
				visit.erase(visit.find(idx));
				idx = perm[idx] - 1;
			}
			nums.insert(num);
		}
		long long ans = 1;
		long long swaps = perm.size() - nums.size();
		ans *= factorial[swaps];
		multiset<long long> swapNums;
		for(long long num : nums) {
			if(num == 1) continue;
			long long swap = 1;
			// for(long long i = 0; i < num; i++) {
			// 	ans *= i+1;
			// 	ans %= MOD;
			// }
			// ans /= 2;
			ans *= factorial[num] / 2;
			ans /= factorial[num - 1];
			// swap = num - 1;
			// for(long long i = 1; i <= swap; i++){
			// 	swapNums.insert(i);
			// }
		}
		auto it = swapNums.begin();

		// for(long long i = 0; i < swaps; i++) {
		// 	ans *= i+1;
		// 	while(it != swapNums.end() && ans % *it == 0){
		// 		ans /= *it;
		// 		it++;
		// 	}
		// 	ans %= MOD;
		// }
		// while(it != swapNums.end()){
		// 	ans /= *it;
		// 	it++;
		// }
		ans %= MOD;

		cout << ans << endl;

	}
	
	return 0;
}