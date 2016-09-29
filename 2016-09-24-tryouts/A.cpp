#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	map<char, string> translate;
	translate['a'] = "@";
	translate['b'] =  "8";
	translate['c'] =  "(";
	translate['d'] =  "|)";
	translate['e'] =  "3";
	translate['f'] =  "#";
	translate['g'] =  "6";
	translate['h'] =  "[-]";
	translate['i'] =  "|";
	translate['j'] =  "_|";
	translate['k'] =  "|<";
	translate['l'] =  "1";
	translate['m'] =  "[]\\/[]";
	translate['n'] =  "[]\\[]";
	translate['o'] =  "0";
	translate['p'] =  "|D";
	translate['q'] =  "(,)";
	translate['r'] =  "|Z";
	translate['s'] =  "$";
	translate['t'] =  "']['";
	translate['u'] =  "|_|";
	translate['v'] =  "\\/";
	translate['w'] =  "\\/\\/";
	translate['x'] =  "}{";
	translate['y'] =  "`/";
	translate['z'] =  "2";

	string s; getline(cin, s);
	string out;
	for(char i : s) {
		if(translate.count(i) != 0) {
			out.append(translate[i]);
		} else if (i >= 'A' && i <= 'Z') {
			out.append(translate[i - 'A' + 'a']);
		} else {
			out.append(1, i);
		}
	}
	cout << out << endl;
	
	return 0;
}