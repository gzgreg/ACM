#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s; cin >> s;

	vector<string> moves;
	string curMove;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == ',') {
			moves.push_back(curMove);
			curMove = "";
		} else {
			curMove.push_back(s[i]);
		}
	}

	moves.push_back(curMove);

	int x = 0, y = 0;
	int ans = 0;
	for(auto cur : moves) {
		if(cur == "n") {
			y += 2;
		} else if (cur == "ne") {
			x++;
			y++;
		} else if (cur == "se") {
			x++;
			y--;
		} else if (cur == "s") {
			y -= 2;
		} else if (cur == "sw") {
			y--;
			x--;
		} else if (cur == "nw") {
			y++;
			x--;
		}
		ans = max(ans, (abs(x) + abs(y)) / 2);
	}
	cout << (abs(x) + abs(y)) / 2 << endl;
	cout << ans << endl;

	return 0;
}