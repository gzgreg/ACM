#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vector<int>> soln3 = {{1, 6, 8}, {2, 4, 9}, {3, 5, 7}};
vector<vector<int>> soln4 = {{4, 5, 6, 11}, {2, 7, 8, 9}, {1, 3, 10, 12}};
vector<vector<int>> soln5 = {{4, 5, 8, 9, 12},
							 {2, 6, 10, 11, 13},
							 {1, 3, 7, 14, 15}};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin >> n;

	if(n == 1 || n == 2) {
		cout << "FAIL" << endl;
		return 0;
	}

	vector<vector<int>> ans;
	int offset = 9;
	if(n % 3 == 0) {
		ans = soln3;
		n -= 3;
	} else if (n % 3 == 1) {
		ans = soln4;
		n -= 4;
		offset = 12;
	} else {
		ans = soln5;
		n -= 5;
		offset = 15;
	}
	while(n > 0) {
		n -= 3;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				ans[i].push_back(soln3[i][j] + offset);
			}
		}
		offset += 9;
	}

	cout << "WIN" << endl;
	for(auto cur : ans) {
		for(auto val : cur) {
			cout << val << " ";
		}
		cout << endl;
	}

	return 0;
}