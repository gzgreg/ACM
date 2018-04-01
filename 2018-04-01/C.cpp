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

	vector<int> expect(vals);
	sort(expect.begin(), expect.end());
	vector<int> actual(n);

	for(int i = 0; i < n-1; i++) {
		if(vals[i] < vals[i+1] - 1) {
			vals[i]++;
			vals[i+1]--;
		} else if (vals[i] > vals[i+1] + 1) {
			vals[i]--;
			vals[i+1]++;
		}
	}
	for(int i = n-1; i >= 0; i--) {
		int maxVal = 0;
		int maxIdx;
		for(int j = 0; j < vals.size(); j++) {
			if(vals[j] > maxVal) {
				maxVal = vals[j];
				maxIdx = j;
			}
		}
		actual[i] = maxVal;
		vals.erase(vals.begin() + maxIdx);

		for(int j = 0; j < ((int) vals.size()) - 1; j++) {
			if(vals[j] < vals[j+1] - 1) {
				vals[j]++;
				vals[j+1]--;
			} else if (vals[j] > vals[j+1] + 1) {
				vals[j]--;
				vals[j+1]++;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		if(expect[i] != actual[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}