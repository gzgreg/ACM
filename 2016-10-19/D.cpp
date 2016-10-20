#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int R, C; cin >> R >> C;

	vector<string> lines;
	for(int i = 0; i < R; i++) {
		string curr; cin >> curr; lines.push_back(curr);
	}
	set<pii> visited;
	pii curr = {0, 0}; visited.insert(curr);
	int moves = 0;
	while(true) {
		char instr = lines[curr.first][curr.second];
		if(instr == 'E') {
			curr = {curr.first, curr.second + 1};
		} else if (instr == 'W') {
			curr = {curr.first, curr.second - 1};
		} else if (instr == 'N') {
			curr = {curr.first - 1, curr.second};
		} else if (instr == 'S') {
			curr = {curr.first + 1, curr.second};
		} else if (instr == 'T') {
			cout << moves << endl;
			return 0;
		}
		moves++;
		if(curr.first >= R || curr.first < 0
			|| curr.second >= C || curr.second < 0) {
			cout << "Out" << endl;
			return 0;
		}
		if(visited.count(curr)) {
			cout << "Lost" << endl;
			return 0;
		}
		visited.insert(curr);
	}
	
	return 0;
}