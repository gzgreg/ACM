#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int n;

pii rotate(pii curr) {
	return {curr.second, n - 1 - curr.first};
}

int main(){
	ios::sync_with_stdio(0);

	cin >> n;

	set<pii> grille;
	set<pii> unseen;
	char grid[n][n];

	memset(grid, '6', sizeof grid);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			char curr; cin >> curr;
			unseen.insert({i, j});
			if(curr == '.') {
				grille.insert({i, j});
			}
		}
	}

	string code; cin >> code;

	if(grille.size() != n*n/4) {
		cout << "invalid grille" << endl;
		return 0;
	}

	int idx = 0;
	for(int i = 0; i < 4; i++) {
		set<pii> newGrille;
		for(pii curr : grille) {
			unseen.erase(curr);
			newGrille.insert(rotate(curr));
			grid[curr.first][curr.second] = code[idx];
			idx++;
		}
		grille = newGrille;
	}

	if(!unseen.empty()) {
		cout << "invalid grille" << endl;
	} else {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << grid[i][j];
			}
		}
		cout << endl;
	}
	
	return 0;
}