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

	for(int i = 0; i < s.size(); i++) {
		if(s[i] != s[s.size() - i - 1]) {
			s[i] = s[s.size() - i - 1];
		}
	}
	cout << s << endl;

	return 0;
}