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
	unordered_map<int, int> dev;
	vector<int> orig;
	ll ans = 1e15, curAns = 0;

	int pos = 0, neg = 0;
	for(int i = 0; i < n; i++) {
		int curr; cin >> curr;
		dev[i + 1 - curr]++;
		orig.push_back(curr - 1);
		curAns += abs(curr-i-1);
		if(curr-i-1 > 0) {
			neg++;
		} else {
			pos++;
		}
	}

	// for(pii curr : dev) {
	// 	cout << curr.first << " " << curr.second << endl;
	// }
	// cout << endl;

	ans = curAns;
	int bestIdx = 0;
	//cout << ans << endl;
	for(int i = 1; i < n; i++) {
		pos--;
		curAns += pos;
		curAns -= neg;
		curAns += 2*orig[n-i] - n + 1;
		if(ans > curAns) {
			bestIdx = i;
			ans = curAns;
		}

		// cout << i << " " << curAns << endl;
		// cout << pos << " " << neg << " " << 2*orig[n-i] - n + 1 << endl;
		// cout << endl;
		neg++;

		dev[n - i - orig[n-i]]--;
		dev[-i - orig[n-i]]++;
		//cout << n - i - orig[n-i] << " " << -i - orig[n-i] << endl;
		pos += dev[-i];
		neg -= dev[-i];
		// cout << dev[-i] << endl;
		// cout << endl;
	}
	// cout << endl;

	cout << ans << " " << bestIdx << endl;
	
	return 0;
}