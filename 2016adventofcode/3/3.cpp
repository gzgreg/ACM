#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	vector<vector<int>> nums;
	int num = 0;
	int x, y, z;
	while(cin >> x) {
		cin >> y >> z;
		nums.push_back({x, y, z});
	}

	for(int i = 0; i < nums.size() / 3; i++) {
		for(int j = 0; j < 3; j++) {
			int a = nums[3*i][j], b = nums[3*i + 1][j], c = nums[3*i + 2][j];

			if(a + b > c
				&& a + c > b
				&& b + c > a) {
				num++;
			}
		}
	}
	cout << num << endl;
	
	return 0;
}