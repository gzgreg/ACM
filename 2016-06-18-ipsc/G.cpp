#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int t; cin >> t;
	while(t--) {
		string s; cin >> s;

		s.erase(remove(s.begin(), s.end(), '('), s.end());
		s.erase(remove(s.begin(), s.end(), ')'), s.end());
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
		s.erase(remove(s.begin(), s.end(), '+'), s.end());
		s.erase(remove(s.begin(), s.end(), '*'), s.end());
		s.erase(0, min(s.find_first_not_of('0'), s.size()-1));
		cout << s << endl;
	}
	
	
	return 0;
}