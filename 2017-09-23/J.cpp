#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin >> n;

	vector<int> vals;
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; vals.push_back(cur);
	}

	for(int val : vals) {
		bitset<8> curVal = val;
		bitset<8> newVal = 0;
		newVal[0] = curVal[0];
		for(int i = 1; i <= 7; i++) {
			if(curVal[i]) {
				newVal[i] = !newVal[i-1];
			} else {
				newVal[i] = newVal[i-1];
			}
		}

		cout << newVal.to_ulong() << " ";
	}
	cout << endl;

	return 0;
}