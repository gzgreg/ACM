#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	ll k; cin >> k;

	while(k != 0) {
		string s; cin >> s;

		int numDigits = 0;

		int a = s.size() + 1;
		bool valid = true;
		while(a != 1) {
			if(a % 2 != 0) {
				valid = false;
				break;
			}
			a = a >> 1;
			numDigits++;
		}
		vector<char> knownDigits (numDigits, '?');
		set<char> unseen;
		for(int i = 1; i < 10; i++) {
			unseen.insert('0' + i); 
		}
		int idx = 0;
		for(int i = 1; i < s.size() + 1; i*=2, idx++) {
			char currDigit = '?';
			for(int j = i; j < s.size() + 1; j += 2*i) {
				if(s[j-1] != '?') {
					if(currDigit == '?') {
						currDigit = s[j-1];
						unseen.erase(currDigit);
					} else if (currDigit != s[j-1]) {
						valid = false;
					}
				}
			}
			if(currDigit != '?'){
				knownDigits[idx] = currDigit;
				numDigits--;
			} 
		}
		if(!valid || knownDigits[0] == '0') {
			cout << -1 << endl;
			cin >> k;
			continue;
		}

		vector<int> newNum;
		k--;
		while(k != 0) {
			newNum.push_back(k % 9);
			k = k / 9;
		}
		if(newNum.size() > numDigits) {
			cout << -1 << endl;
			cin >> k;
			continue;
		}
		while(newNum.size() < numDigits) {
			newNum.push_back(0);
		}
		reverse(newNum.begin(), newNum.end());
		if(knownDigits[0] == '?' && newNum.size() > 0 && newNum[0] >= unseen.size()) {
			cout << -1 << endl;
			cin >> k;
			continue;
		}
		for(int i = 0, j = 0; i < knownDigits.size(); i++) {
			if(knownDigits[i] == '?') {
				if(i == 0) {
					int k = 0;
					for(auto it = unseen.begin(); it != unseen.end(); it++, k++) {
						if(newNum[j] == k) {
							knownDigits[i] = *it;
							break;
						}
					}
				} else if(newNum[j] + '0' >= knownDigits[0]) {
					knownDigits[i] = '0' + newNum[j] + 1;
				} else {
					knownDigits[i] = '0' + newNum[j];
				}
				j++;
			}
		}
		idx = 0;
		for(int i = 1; i < s.size() + 1; i*=2, idx++) {
			char currDigit = knownDigits[idx];
			for(int j = i; j < s.size() + 1; j += 2*i) {
				s[j-1] = currDigit;
			}
		}
		cout << s << endl;

		cin >> k;
	}
	
	return 0;
}