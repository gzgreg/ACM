#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	long long T; cin >> T;
	while(T--){
		long long N; cin >> N;
		list<long long> nums;
		for(long long i = 0; i < N; i++){
			long long curr; cin >> curr;
			nums.push_back(curr);
		}

		bool reduced = false;
		bool chg = false;
		for(auto it = nums.begin(); it != nums.end(); it++){
			long long curr = *it;
			it++;
			if(it == nums.end()) break;
			long long next = *it;
			it--;
			if(curr+next == 3 || (curr == next && curr%3 == 0)){
				if(*it % 3 != 0){
					it = nums.erase(it);
					*it = 3;
				}
				chg = true;			
			}
		}
		if(!chg) reduced = true;
		int currPow = 0;
		while(!reduced){
			bool changed = false;
			for(auto it = nums.begin(); it != nums.end(); it++){
				long long curr = *it;
				it++;
				if(it == nums.end()) break;
				long long next = *it;
				it--;
				if(curr == next && curr%3 == 0){
					if(*it == 3*pow(2, currPow)){
						it = nums.erase(it);
						*it = *it * 2;
					}
					changed = true;
				}
			}
			if(!changed) reduced = true;
			currPow++;
		}
		long long max = 0;
		for(auto it = nums.begin(); it != nums.end(); it++){
			if(*it > max) max = *it;
		}
		cout << max << endl;
	}

	return 0;
}