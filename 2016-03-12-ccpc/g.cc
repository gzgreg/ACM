#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		int n,m; cin >> n >> m;
		vector<int> board;
		for (int i=0; i<n+1; i++) {
			int a; cin >> a;
			board.push_back(a);
		}
		bool win = false;
		int curr = 0;
		string s; cin >> s;
		for (int i=0; i<m; i++) {
			int b = s[i] - '0';
			if ((curr+b)<=n) {
				curr += b;
				curr += board[curr];
			}
			if (curr == n) {
				win = true;
				break;
			}
		}
		if (win) cout << "win" << endl;
		else cout << "game in progress" << endl;
	}
	return 0;
}