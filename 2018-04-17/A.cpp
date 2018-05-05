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
	string s; cin >> s;
	bool good = false;
	for(int i = 0; i < n; i++) {
		if(s[i] == '?') {
			if(i == 0 || i == n-1) good = true;
			else if (s[i-1] == '?' || s[i+1] == '?') good = true;
			else if (s[i-1] == s[i+1]) good = true;
		} else {
			if(i == 0) {
				if(s[i] == s[i+1]) {
					good = false;
					break;
				}
			} else if (i == n-1) {
				if(s[i] == s[i-1]) {
					good = false;
					break;
				}
			} else {
				if(s[i] == s[i+1]
					|| s[i] == s[i-1]) {
					good = false;
					break;
				}
			}
		}
	}

	if(good) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}