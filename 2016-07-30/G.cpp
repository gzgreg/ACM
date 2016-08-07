#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int n, x; cin >> n >> x;
	x--;
	string s; cin >> s;
	int m; cin >> m;
	string prog; cin >> prog;
	string out = ""; out.append(1, s[x]);
	for(int i = 0; i < prog.length(); i++) {
		char curr = prog[i];
		if(curr == 'L') {
			x--;
		} else {
			x++;
		}

		out.append(1, s[x]);
	}

	cout << out << endl;
	
	return 0;
}