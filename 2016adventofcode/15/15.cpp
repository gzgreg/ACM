#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	vector<pair<int, int>> nums;

	nums.push_back({17, 15});
	nums.push_back({3, 2});
	nums.push_back({19, 4});
	nums.push_back({13, 2});
	nums.push_back({7, 2});
	nums.push_back({5, 0});
	nums.push_back({11, 0});

	int i = 0;
	while(i < 1e8) {
		int j = 0;
		bool found = true;
		for(pii curr : nums) {
			if((curr.second + i + j + 1) % curr.first != 0) {
				found = false;
				break;
			}
			j++;
		}
		if(found) {
			cout << i << endl;
			return 0;
		}
		i++;
	}
	
	return 0;
}