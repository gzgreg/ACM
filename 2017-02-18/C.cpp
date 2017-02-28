#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	
	string code; cin >> code;
	string key; cin >> key;

	string ans = "";

	for(int i = 0; i < key.size() && i < code.size(); i++) {
		int currChar = code[i];
		currChar -= key[i];
		currChar = (currChar + 26) % 26;
		currChar += 'A';
		ans.push_back((char) currChar);
	}

	for(int i = key.size(); i < code.size(); i++) {
		int currChar = code[i];
		currChar -= ans[i-key.size()];
		currChar = (currChar + 26) % 26;
		currChar += 'A';
		ans.push_back((char) currChar);
	}

	cout << ans << endl;

	return 0;
}