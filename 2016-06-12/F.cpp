#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int n, m; cin >> n >> m;

	vector<vector<int>> yard;

	for(int i = 0; i < n; i++) {
		yard.push_back(vector<int> ());
		for(int j = 0; j < m; j++) {
			char curr; cin >> curr; yard[i].push_back(curr);
		}
	}

	int currLength = 0;
	vector<int> ans (max(n, m), 0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(yard[i][j] == '.') {
				currLength++;
			} else if (currLength != 0) {
				for(int k = 0; k < currLength; k++) {
					ans[k] += currLength - k;
				}
				currLength = 0;
			}
		}
		if (currLength != 0) {
			for(int k = 0; k < currLength; k++) {
				ans[k] += currLength - k;
			}
			currLength = 0;
		}
	}

	if (currLength != 0) {
		for(int k = 0; k < currLength; k++) {
			ans[k] += currLength - k;
		}
		currLength = 0;
	}

	for(int j = 0; j < m; j++) {
		for(int i = 0; i < n; i++) {
			if(yard[i][j] == '.') {
				currLength++;
			} else if (currLength != 0) {
				for(int k = 1; k < currLength; k++) {
					ans[k] += currLength - k;
				}
				currLength = 0;
			}
		}
		if (currLength != 0) {
			for(int k = 1; k < currLength; k++) {
				ans[k] += currLength - k;
			}
			currLength = 0;
		}
	}

	if (currLength != 0) {
		for(int k = 1; k < currLength; k++) {
			ans[k] += currLength - k;
		}
		currLength = 0;
	}

	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	
	return 0;
}