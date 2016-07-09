#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	long long T; cin >> T;
	for(long long i = 0; i < T; i++){
		long long N, P; cin >> N >> P;
		vector<long long> nums, cumsum;
		nums.push_back(0);
		cumsum.push_back(0);
		long long currsum = 0;
		for(long long j = 0; j < N; j++){
			long long curr; cin >> curr; nums.push_back(curr);
			currsum += curr; cumsum.push_back(currsum);
		}
		long long tot = 0;
		for(long long j = 1; j < nums.size(); j++){
			long long b = nums.size() - 1;
			long long a = j;
			long long diff = (b - a) / 2;
			while(b != a){
				if(cumsum[b] - cumsum[a - 1] > P){
					b -= diff;
					if(diff / 2 > 0){
						diff /= 2;
					} else {
						diff = 1;
					}
				} else {
					a += diff;
					if(diff / 2 > 0){
						diff /= 2;
					} else {
						diff = 1;
					}
				}
			}

			if(cumsum[b] - cumsum[j - 1] > P || (b == j && nums[b] > P)) b--;
			tot += b - j + 1;	
		}
		cout << "Case #" << i+1 << ": " << tot << endl;
	}

	return 0;
}