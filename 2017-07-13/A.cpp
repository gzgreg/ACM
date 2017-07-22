#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	
	int n; cin >> n;
	bool isIncreasing = true;
	bool isConstant = false;
	int last;
	for(int i = 0; i < n; i++) {
		int curr; cin >> curr;
		if(i == 0) {
			last = curr;
			continue;
		} else if (isIncreasing) {
			if(curr == last) {
				isIncreasing = false;
				isConstant = true;
			} else if (curr < last) {
				isIncreasing = false;
				isConstant = false;
			}
		} else if (isConstant) {
			if(curr > last) {
				cout << "NO" << endl;
				return 0;
			} else if (curr < last) {
				isConstant = false;
			}
		} else {
			if(curr >= last) {
				cout << "NO" << endl;
				return 0;
			}
		}

		last = curr;
	}

	cout << "YES" << endl;

	return 0;
}