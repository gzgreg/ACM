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

	stack<char> val;
	int depth = 0;
	int score = 0;
	bool ignore = false;
	int ans = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '>'){
			ignore = false;
		}
		if(s[i] == '!') {
			i++;
		} else {
			if(ignore) ans++;
		}
		if(ignore) continue;
		if(s[i] == '{') {
			depth++;
		} else if(s[i] == '}') {
			score += depth;
			depth--;
		} else if (s[i] == '<') {
			ignore = true;
		}
	}

	cout << ans<< endl;
	
	return 0;
}