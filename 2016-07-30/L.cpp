#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;
	string s; cin >> s;
	int smiles = 0; 
	int frowns = 0;
	for(int i = 1; i < s.length(); i++) {
		char first = s[i-1];
		char second = s[i];
		if(first == ':') {
			if(second == ')') {
				smiles++;
			} else if (second == '(') {
				frowns++;
			}
		} else if (second == ':') {
			if (first == '(') {
				smiles++;
			} else if (first == ')') {
				frowns++;
			}
		}
	}
	
	if(smiles > frowns) {
		cout << "HAPPY" << endl;
	} else if (smiles == frowns) {
		cout << "BORED" << endl;
	} else {
		cout << "SAD" << endl;
	}

	return 0;
}