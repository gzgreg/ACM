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
	
	int L, C; cin >> L >> C;
	vector<vector<int>> vals(L, vector<int>(C));

	for(int i = 0; i < L; i++) {
		for(int j = 0; j < C; j++) {
			cin >> vals[i][j];
			vals[i][j]--;
		}
	}
	int ans = 0;

	for(int i = 0; i < L; i++) {
		for(int j = 0; j < C; j++) {
			if(vals[i][j] / C != vals[i][0] / C) {
				cout << "*" << endl;
				return 0;
			}
			if(vals[i][j] % C != vals[0][j] % C) {
				cout << "*" << endl;
				return 0;
			}
		}
	}

	vector<int> rows, cols;
	for(int i = 0; i < L; i++) {
		rows.push_back(vals[i][0] / C);
	}
	for(int i = 0; i < C; i++) {
		cols.push_back(vals[0][i] % C);
	}

	set<int> seenRows, seenCols;
	for(int i = 0; i < L; i++) {
		if(seenRows.count(i)) continue;
		int start = i;
		int sz = 0;
		while(!seenRows.count(start)) {
			seenRows.insert(start);
			sz++;
			start = rows[start];
		}
		ans += sz - 1;
	}
	for(int i = 0; i < C; i++) {
		if(seenCols.count(i)) continue;
		int start = i;
		int sz = 0;
		while(!seenCols.count(start)) {
			seenCols.insert(start);
			sz++;
			start = cols[start];
		}
		ans += sz - 1;
	}

	cout << ans << endl;

	return 0;
}