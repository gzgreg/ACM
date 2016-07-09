#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	string s; cin >> s;

	int idx = -1;
	bool leftTried = false;

	for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
		if(s[i] != s[j]) {
			if(idx == -1) {
				idx = i;
				j++;
			} else if (!leftTried) {
				leftTried = true;
				j += (i - idx - 1);
				i = idx;
				idx = j;
				i--;
			} else {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	
	if(idx == -1) {
		idx = s.size() / 2;
	}

	cout << "YES" << endl;
	cout << idx + 1 << endl;

	return 0;
}