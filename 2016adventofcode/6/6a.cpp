#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	
	vector<map<char, int>> freq (8, map<char, int>());

	string s;
	while(cin >> s) {
		for(int i = 0; i < 8; i++) {
			freq[i][s[i]]++;
		}
	}
	string password = "";
	for(int i = 0; i < 8; i++) {
		char bestChar = 'a';
		for(pair<char, int> val : freq[i]) {
			if(val.second <= freq[i][bestChar]) {
				bestChar = val.first;
			}
		}
		password.push_back(bestChar);
	}

	cout << password << endl;

	return 0;
}