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

	int X; cin >> X;

	string s; cin >> s;
	int diff = 0, ans = 0;
	stack<bool> vals;
	reverse(s.begin(), s.end());
	for(auto cur : s) {
		//cout << (cur == 'W');
		vals.push(cur == 'W');
	}
	//cout << endl;

	while(!vals.empty()) {
		bool cur = vals.top();
		vals.pop();
		if(vals.empty()) {
			if(diff > 0) {
				if (!cur) {
					diff--;
				} else {
					diff++;
				}
			} else {
				if (cur) {
					diff++;
				} else {
					diff--;
				}
			}

			if(abs(diff) > X) {
				cout << ans << endl;
				return 0;
			}
			ans++;
			break;
		}
		bool next = vals.top();
		vals.pop();
		if(diff > 0) {
			if (!cur) {
				diff--;
				vals.push(next);
			} else if (!next) {
				diff--;
				vals.push(cur);
			} else {
				diff++;
				vals.push(next);
			}
		} else {
			if (cur) {
				diff++;
				vals.push(next);
			} else if (next) {
				diff++;
				vals.push(cur);
			} else {
				diff--;
				vals.push(next);
			}
		}
		if(abs(diff) > X) {
			cout << ans << endl;
			return 0;
		}

		ans++;
		//cout << cur << " " << next << " ";
		//cout << diff << " " << ans << endl;
	}

	cout << ans << endl;
	
	return 0;
}