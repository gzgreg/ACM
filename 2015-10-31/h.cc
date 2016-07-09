#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl '\n'

bool find(string str, char c) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == c) return true;
	}
	return false;
}

string replace(string str, char ch1, char ch2) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ch1) str[i] = ch2;
	}

	return str;
}

int main() {
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		string a,b,c;
		int i=0;
		if (s[0] == '-') i++;

		while(s[i] != '+' && s[i] != '-' && s[i] != '*') i++;
		a = s.substr(0,i);
		char op = s[i];
		i++;
		int j=0;
		while(s[i+j] != '=') j++;
		b = s.substr(i,j);
		c = s.substr(i+j+1);
		char newc;

		for (int i=0; i<10; i++) {
			newc = '0'+(char)i;
			if (find(a,newc) || find(b,newc) || find(c,newc)) continue;
			string a1 = replace(a,'?',newc);
			string b1 = replace(b,'?',newc);
			string c1 = replace(c,'?',newc);

			int a2 = atoi(a1.c_str());
			int b2 = atoi(b1.c_str());
			int c2 = atoi(c1.c_str());
			if(i == 0){
				if(a1[0] == '0' || b1[0] == '0' || c1[0]== '0') continue;
				if((a1[0] == '-' && a1[1] == '0') ||
					(b1[0] == '-' && b1[1] == '0') ||
					(c1[0] == '-' && c1[1] == '0')) continue;
			}
			if (op == '+') {
				if (a2 + b2 == c2) {
					cout << i << endl;
					goto control_flow_lol;
				}
			}
			if (op == '*') {
				if (a2 * b2 == c2) {
					cout << i << endl;
					goto control_flow_lol;
				}
			}
			if (op == '-') {
				if (a2 - b2 == c2) {
					cout << i << endl;
					goto control_flow_lol;
				}
			}
		}
		cout << -1 << endl;
		control_flow_lol:;
	}
	return 0;
}