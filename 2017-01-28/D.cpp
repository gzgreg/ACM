#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	while(T--) {
		int R, C; cin >> R >> C;

		vector<string> soln (R, "");
		for(int i = 0; i < R; i++) {
			string curr; cin >> curr; soln[i] = curr;
		}

		vector<vector<int>> descr (R, vector<int>(C, 0));
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				int curr; cin >> curr; descr[i][j] = curr;
			}
		}

		set<set<pii>> groups;
		set<pii> unvisited;

		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				char currNum = soln[i][j];

				for(int k = i + 1; k < i + currNum + 1 - '0' && k < R; k++) {
					if(currNum == soln[k][j]) {
						cout << "invalid" << endl;
						goto failed;
					}
				}
				for(int k = j + 1; k < j + currNum + 1- '0' && k < C; k++) {
					if(currNum == soln[i][k]) {
						cout << "invalid" << endl;
						goto failed;
					}
				}

			}
		}

		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				unvisited.insert({i, j});
			}
		}

		while(!unvisited.empty()) {
			queue<pii> bfsq;
			bfsq.push(*(unvisited.begin()));

			set<pii> currSet;

			while(!bfsq.empty()) {
				pii curr = bfsq.front(); bfsq.pop();
				currSet.insert(curr);
				unvisited.erase(curr);

				bitset<4> dir (descr[curr.first][curr.second]);
				if(dir[0] && unvisited.count({curr.first - 1, curr.second})) {
					bfsq.push({curr.first - 1, curr.second});
				}
				if(dir[1] && unvisited.count({curr.first, curr.second + 1})) {
					bfsq.push({curr.first, curr.second + 1});
				}
				if(dir[2] && unvisited.count({curr.first + 1, curr.second})) {
					bfsq.push({curr.first + 1, curr.second});
				}
				if(dir[3] && unvisited.count({curr.first, curr.second - 1})) {
					bfsq.push({curr.first, curr.second - 1});
				}
			}
			groups.insert(currSet);
		}
		for(set<pii> group : groups) {
			set<char> nums;
			for(pii curr : group) {
				nums.insert(soln[curr.first][curr.second]);
			}
			if(nums.size() != group.size() || !nums.count(nums.size() + '0')) {
				cout << "invalid" << endl;
				goto failed;
			}
		}
		cout << "valid" << endl;
		failed: ;
	}
	
	return 0;
}