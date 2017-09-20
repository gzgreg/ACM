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
	if(s.size() > 26) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	set<char> used;
	map<char, int> uses;
	for(int i = 0; i < s.size(); i++) {
		used.insert(s[i]);
		uses[s[i]]++;
	}

	for(int i = 0; i < s.size(); i++) {
		if(uses[s[i]] > 1) {
			uses[s[i]]--;
			for(int j = 0; j < 26; j++) {
				if(!used.count('a' + j)) {
					used.insert('a' + j);
					s[i] = 'a' + j;
					break;
				}
			}
		}
	}

	cout << s << endl;
	
	return 0;
}