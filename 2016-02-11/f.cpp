#include <bits/stdc++.h>

// #define INF 1e10

using namespace std;

// long long dp(vector<long long> spots, vector<vector<long long> > memo, int idx, int cows){
// 	if(spots.size() - idx < cows) return 0;
// 	if(memo[idx][cows] != INF) return memo[idx][cows];
// 	if(cows == 2){
// 		//cout << idx << " " << cows << " " << spots[spots.size() - 1] - spots[idx] << endl;
// 		memo[idx][cows] = spots[spots.size() - 1] - spots[idx];
// 		return spots[spots.size() - 1] - spots[idx];
// 	} 

// 	long long minval = 0;
// 	for(int i = idx+1; i <= spots.size() - cows; i++){
// 		minval = max(minval, min(dp(spots, memo, i, cows - 1), spots[i] - spots[idx]));
// 	}
// 	//cout << idx << " " << cows << " " << minval << endl;
// 	memo[idx][cows] = minval;
// 	return minval;
// }

// int main(){
// 	//ios::sync_with_stdio(0);

// 	int t; cin >> t;
// 	while(t--){
// 		int N, C; cin >> N >> C;
// 		vector<long long> spots;
// 		vector<vector<long long> > memo;
// 		for(int i = 0; i < N; i++){
// 			long long curr; scanf("%lld", &curr);
// 			spots.push_back(curr);
// 			vector<long long> empty (N, INF);
// 			memo.push_back(empty);
// 		}
// 		sort(spots.begin(), spots.end());
// 		//memset(memo, 0, sizeof memo);
// 		cout << dp(spots, memo, 0, C) << endl;
// 	}

// 	return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int main(){
	//ios::sync_with_stdio(0);

	int t; cin >> t;
	while(t--){
		int N, C; cin >> N >> C;
		vector<long long> spots;
		for(int i = 0; i < N; i++){
			long long curr; scanf("%lld", &curr);
			spots.push_back(curr);
		}
		sort(spots.begin(), spots.end());

		long long b = spots[spots.size() - 1];
		long long diff = b / 2;
		long long a = 0;

		while(a != b){
			int loc = 0;
			int idx = 1;
			bool doable = true;
			for(int i = 0; i < C - 1; i++){
				while(spots[idx] - spots[loc] < (double) (b + a) / 2){
					idx++;
					if(idx >= spots.size()){
						doable = false;
						break;
					}
				}
				if(!doable) break;
				loc = idx;
			}
			if(doable){
				a += diff;
			} else {
				b -= diff;
			}

			if(diff > 1) {
				diff /= 2;
			} else {
				diff = 1;
			}
		}

		cout << b << endl;

	}

	return 0;
}
