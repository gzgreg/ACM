#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<string> bs = {"@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "\'][\'", "|_|", "\\/", "\\/\\/", "}{", "`/", "2"};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s; getline(cin, s);
	for(char cur : s) {
		if(isalpha(cur)) {
			cout << bs[tolower(cur) - 'a'];
		} else {
			cout << cur;
		}
	}
	cout << endl;
	return 0;
}