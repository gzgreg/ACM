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
	string j; getline(cin, j);
	while(n--) {
		string s2; getline(cin, s2);
		string s = s2.substr(2);
		if(s2[0] == 'e') {
			vector<int> vals;
			vals.push_back(0);
			for(int i = 0; i < s.size(); i++) {
				vals.push_back(vals.back() + (s[i] - 'a') + 1);
				if(s[i] == ' ') {
					vals[vals.size() - 1] = vals[vals.size() - 2];
				}
				vals[i+1] %= 27;
			}

			for(int i = 0; i < s.size(); i++) {
				if(vals[i+1] == 0) {
					cout << " ";
				} else {
					cout << char(vals[i+1] + 'a' - 1);
				}
			}
			cout << endl;
		} else {
			vector<int> vals;
			vals.push_back(0);
			for(int i = 0; i < s.size(); i++) {
				int curVal = 0;
				if(s[i] != ' ') {
					curVal = s[i] - 'a' + 1;
				}
				while(curVal < vals.back()) {
					curVal += 27;
				}
				vals.push_back(curVal);
			}

			for(int i = 0; i < s.size(); i++) {
				if(vals[i] == vals[i+1]) {
					cout << " ";
				} else {
					cout << char(vals[i+1] - vals[i] + 'a' - 1);
				}
			}
			cout << endl;
		}
	}
	
	return 0;
}