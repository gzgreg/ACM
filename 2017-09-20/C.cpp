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

	string s; cin >> s;

	string out; out.push_back(s[0]); out.push_back(s[1]);

	set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
	int runLength = 0;
	if(s.size() < 2) {
		cout << s << endl;
		return 0;
	}
	if(!vowels.count(s[1])) {
		runLength++;
		if(!vowels.count(s[0])) {
			runLength++;
		}
	}
	for(int i = 2; i < s.size(); i++) {
		if(vowels.count(s[i])) {
			runLength = 0;
		} else {
			runLength++;
			if(s[i] == s[i-1] && s[i] == s[i-2]) {
				runLength = 2;
			}
			if((runLength % 2 == 1) && runLength > 1) {
				out.push_back(' ');
			}
		}
		out.push_back(s[i]);
	}

	cout << out << endl;
	
	return 0;
}