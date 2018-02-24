#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<string> tok;

void dfs(int idx) {

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s; getline(cin, s);

	tok.push_back("");
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == ' ') tok.push_back("");
		else tok.back().push_back(s[i]);
	}

	dfs(0, map<char, int>());

	return 0;
}