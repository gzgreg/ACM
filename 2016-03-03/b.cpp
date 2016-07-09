#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int n, m, k; cin >> n >> m >> k;

	stack<pair<int, pair<int, int> > > ops;

	for(int i = 0; i < k; i++){
		int id, ri, ai; cin >> id >> ri >> ai;
		ops.push(make_pair(id, make_pair(ri, ai)));
	}

	int table[n+1][m+1]; memset(table, 0, sizeof table);

	vector<bool> filledRows (5000, false);
	vector<bool> filledCols (5000, false);

	while(!ops.empty()){
		pair<int, pair<int, int> > curr = ops.top();
		ops.pop();

		pair<int, int> data = curr.second;

		if(curr.first == 1 && !filledRows[data.first]){
			filledRows[data.first] = true;
			for(int i = 0; i < m+1; i++){
				if(table[data.first][i] == 0){
					table[data.first][i] = data.second;
				}
			}
		} else if(curr.first == 2 && !filledCols[data.first]){
			filledCols[data.first] = true;
			for(int i = 0; i < n+1; i++){
				if(table[i][data.first] == 0){
					table[i][data.first] = data.second;
				}
			}
		}
	}

	for(int i = 1; i < n+1; i++){
		for(int j = 1; j < m+1; j++){
			cout << table[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}