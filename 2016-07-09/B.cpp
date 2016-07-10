#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){

	freopen("chip.in", "r", stdin);
	freopen("chip.out", "w", stdout);

	int m, n, h; cin >> m >> n >> h;
	vector<int> a;
	int totalCells = 0;
	for(int i = 0; i < m; i++) {
		int curr; cin >> curr; a.push_back(curr); totalCells += curr;
	}
	map<int, map<int, bool>> b; //map # of unquantizers to columns with that many
	map<int, int> bSize;
	int maxQuants = 0;
	for(int i = 0; i < n; i++) {
		int curr; cin >> curr; b[curr][i] = true;
		bSize[curr]++;
		maxQuants = max(maxQuants, curr);
		totalCells += curr*h;
	}

	if(totalCells != m*n) {
		cout << "inconsistent" << endl;
		return 0;
	}

	vector<vector<int>> quantTops (n, vector<int>());
	vector<int> quantLeft (n, 0);
	int quantNumThisRow = 0;

	for(int i = 0; i < m; i++) {
		int numQuants = n - a[i] - quantNumThisRow;
		if(numQuants < 0) {
			cout << "inconsistent" << endl;
			return 0;
		}
		int currMaxQuants = maxQuants;
		while(numQuants > 0) {
			for(pair<int, bool> curr : b[currMaxQuants]) {
				int currCol = curr.first;
				if(!curr.second) continue;
				if(quantLeft[currCol] != 0) {
					//another unquantizer is in the way
					continue;
				} else {
					quantTops[currCol].push_back(i);
					quantLeft[currCol] = h;
					quantNumThisRow++;
					b[currMaxQuants][currCol] = false;
					b[currMaxQuants - 1][currCol] = true;
					bSize[currMaxQuants]--;
					bSize[currMaxQuants-1]++;
					numQuants--;
					if(numQuants == 0) break;
				}
			}
			currMaxQuants--;
		}
		while(bSize[maxQuants] == 0) {
			maxQuants--;
		}
		for(int i = 0; i < n; i++){
			if(quantLeft[i] > 0) {
				quantLeft[i]--;
				if(quantLeft[i] == 0) {
					quantNumThisRow--;
				}
			}
		}
	}

	if(quantNumThisRow > 0) {
		cout << "inconsistent" << endl;
		return 0;
	}

	vector<vector<char>> tileMap (m, vector<char> (n, '*'));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < quantTops[i].size(); j++) {
			int top = quantTops[i][j];
			tileMap[top][i] = '+';
			for(int k = 1; k < h-1; k++) {
				tileMap[top+k][i] = '|';
			}
			tileMap[top+h-1][i] = '+';
		}
	}
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cout << tileMap[i][j];
		}
		cout << endl;
	}
	return 0;
}