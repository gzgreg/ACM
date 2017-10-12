#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<string> known = {"0", "1", "2", "6", "24", "120", "720"};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s; cin >> s;
	double ans = 0;

	if(s.size() <= 3) {
		for(int i = 0; i < known.size(); i++) {
			if(s == known[i]) {
				cout << i << endl;
				return 0;
			}
		}
	}
	for(int i = 1; ; i++) {
		ans += log10(i);
		if(ans >= (double) s.size()) {
			cout << i-1 << endl;
			return 0;
		}
	}
	
	return 0;
}