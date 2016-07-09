#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int n, m; cin >> n >> m;

	vector<int> nums;

	for(int i = 0; i < n; i++){
		int curr; cin >> curr; nums.push_back(curr);
	}

	vector<pair<int, int>> vals;

	for(int i = 0; i < m; i++){
		int curr1, curr2; cin >> curr1 >> curr2; vals.push_back(make_pair(curr1, curr2));
	}
	int maxIdx = 0;
	for(int i = 1; i < vals.size(); i++){
		if(vals[maxIdx].second <= vals[i].second){
			maxIdx = i;
		}
	}
	int max = 200001;
	vector<pair<int, int>> sorts;

	for(int i = maxIdx; i < vals.size(); i++){
		if(vals[i].second >= max){
			while(sorts[sorts.size() - 1].second <= vals[i].second) sorts.pop_back();
			sorts.push_back(vals[i]);
		} else if(vals[i].second < max){
			sorts.push_back(vals[i]);
			max = vals[i].second;
		}
	}

	for(int i = 0; i < sorts.size(); i++){
		if(i > 0 && sorts[i].first == sorts[i - 1].first) continue;
		//cout << sorts[i].first << " " << sorts[i].second << endl;
		sort(nums.begin(), nums.begin() + sorts[i].second);
		if(sorts[i].first == 2){
			reverse(nums.begin(), nums.begin() + sorts[i].second);
		}
	}

	for(int i=0; i < nums.size(); i++){
		cout << nums[i] << " ";
	}
	cout << endl;

	return 0;
}