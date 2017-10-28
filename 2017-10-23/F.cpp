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

	vector<string> cur;
	for(int i = 0; i < n; i++) {
		string s; cin >> s; cur.push_back(s);
	}

	vector<string> sorted(cur);
	sort(cur.begin(), cur.end());
	bool good = true;
	for(int i = 0; i < n; i++) {
		if(sorted[i] != cur[i]) {
			good = false;
			break;
		}
	}

	if(good) {
		cout << "INCREASING" << endl;
		return 0;
	}

	good = true;
	reverse(cur.begin(), cur.end());

	for(int i = 0; i < n; i++) {
		if(sorted[i] != cur[i]) {
			good = false;
			break;
		}
	}

	if(good) {
		cout << "DECREASING" << endl;
	} else {
		cout << "NEITHER" << endl;
	}
	
	return 0;
}