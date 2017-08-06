#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	int n; cin >> n;
	int k; cin >> k;

	string s; cin >> s;

	set<int> opens, closes;

	for(int i = 0; i < 26; i++) {
		int openTime = -1;
		int closeTime = -1;
		for(int j = 0; j < s.size(); j++) {
			if(s[j] - 'A' == i) {
				if(openTime == -1) openTime = j;
				closeTime = j;
			}
		}
		//cout << openTime << " " << closeTime << endl;
		if(openTime != -1) {
			opens.insert(openTime);
			closes.insert(closeTime);
		}
	}
	auto it = opens.begin();
	int curOpen = 0, maxOpen = 0;
	for(int i : closes) {
		while(i >= *it && it != opens.end()) {
			it++;
			curOpen++;
		}
		//cout << curOpen << endl;
		maxOpen = max(maxOpen, curOpen);
		curOpen--;
	}
	cout << (maxOpen > k ? "YES" : "NO") << endl;
	
	return 0;
}