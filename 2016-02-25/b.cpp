#include <bits/stdc++.h>

using namespace std;

int memo[200][200][200];

int dp(vector<int> nums){
	if(memo[nums[0]][nums[1]][nums[2]] != 0){
		return memo[nums[0]][nums[1]][nums[2]];
	}
	if(nums[0] + nums[1] + nums[2] == 1){
		if(nums[0] == 1) return 1;
		if(nums[1] == 1) return 2;
		if(nums[2] == 1) return 4;
	}
	int result = 0;
	for(int i = 0; i < 3; i++){
		if(nums[i] >= 2){
			vector<int> copy (nums);
			copy[i] -= 1;
			result = result | dp(copy);
		}
		if(nums[i] >= 1){
			for(int j = 0; j < 3; j++){
				if(j == i) continue;
				if(nums[j] >= 1){
					vector<int> copy (nums);
					copy[i]--;
					copy[j]--;
					int k;
					if(i != 0 && j != 0){
						k = 0;
					} else if (i != 1 && j != 1){
						k = 1;
					} else {
						k = 2;
					}
					copy[k]++;
					result = result | dp(copy);
				}
			}
		}
	}
	memo[nums[0]][nums[1]][nums[2]] = result;
	return result;
}

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;

	vector<int> nums (3, 0);

	string s; cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'R'){
			nums[0]++;
		} else if(s[i] == 'B'){
			nums[1]++;
		} else {
			nums[2]++;
		}
	}

	memset(memo, 0, sizeof memo);
	int out = dp(nums);
	if((out & 2) == 2){
		cout << "B";
	}
	if((out & 4) == 4){
		cout << "G";
	}
	if((out & 1) == 1){
		cout << "R";
	}
	cout << endl;

	return 0;
}