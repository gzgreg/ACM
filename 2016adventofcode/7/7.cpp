#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	string s;
	int total = 0;
	while(cin >> s) {
		bool bracketed = false;
		char lastC = '0';
		bool found = false;
		set<pair<char, char>> pairs;
		set<pair<char, char>> pairs2;
		for(int i = 0; i < s.size(); i++) {
			char c = s[i];
			if(c == '[') {
				bracketed = true;
			} else if (c == ']') {
				bracketed = false;
			} else {
				if(i > 1 && c == s[i-2] && c != s[i-1]) {
					if(bracketed) {
						if(pairs.count({c, s[i-1]})) {
							found = true;
							break;
						}
						pairs2.insert({c, s[i-1]});
					} else {
						if(pairs2.count({s[i-1], c})) {
							found = true;
							break;
						}
						pairs.insert({s[i-1], c});
					}
				}

				lastC = c;
			}
		}

		total += found;

	}

	cout << total << endl;
	
	return 0;
}