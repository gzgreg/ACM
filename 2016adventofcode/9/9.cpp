#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

long long recurse(string s) {
	long long ans = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(') {
			i++;
			string length, times;
			while(s[i] != 'x') {
				length.push_back(s[i]);
				i++;
			}
			i++;
			while(s[i] != ')') {
				times.push_back(s[i]);
				i++;
			}
			i++;
			int lastI = i;
			int lInt, tInt;
			lInt = atoi(length.c_str());
			tInt = atoi(times.c_str());
			string rep;
			for(int j = 0; j < lInt; j++) {
				rep.push_back(s[i]);
				i++;
			}
			//part 1: ans += tInt * rep.size();
			ans += tInt * recurse(rep);
			i--;
		} else {
			ans++;
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	
	string s; cin >> s;

	string out;
	long long length = recurse(s);
	cout << length << endl;

	return 0;
}