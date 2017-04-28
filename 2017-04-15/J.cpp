#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	string s; cin >> s;

	int diff = 0;
	for(int i = 0; i < s.size(); i++) {
		diff += (s[i] == 'B' ? 1 : -1);
	}

	if(diff == 0) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
	
	return 0;
}