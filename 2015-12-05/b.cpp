#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int h, w; cin >> h >> w;
	int caseNum = 1;
	while(h != 0){
		int vals[h][w];
		bool seen[h][w];
		vector<pair<int, int> > starts;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				char val; cin >> val;
				vals[i][j] = val - 'A';
				seen[i][j] = false;
				if(val == 'A'){
					starts.push_back(make_pair(i, j));
				}
			}
		}
		int maxLength = 0;

		for(int i = 0; i < starts.size(); i++){
			// stack<pair<int, int> > dfs;
			// dfs.push(start);
			// while(!dfs.empty()){
			// 	pair<int, int> curr = dfs.top();
			// 	dfs.pop();
			// 	int currVal = vals[curr.first][curr.second];
			// 	if(!seen[curr.first][curr.second]){
			// 		seen[curr.first][curr.second] = true;
			// 		if(currVal + 1 > maxLength) maxLength = currVal + 1;
			// 		for(int j = curr.first-1; j <= curr.first+1; j++){
			// 			if(j < 0 || j >= h) continue;
			// 			for(int k = curr.second - 1; k <= curr.second + 1; k++){
			// 				if(k < 0 || k >= w) continue;
			// 				if(vals[j][k] == currVal + 1){
			// 					dfs.push(make_pair(j, k));
			// 				}
			// 			}
			// 		}
			// 	}
			// }

		}

		cout << "Case " << caseNum << ": " << maxLength << endl;
		caseNum++;
		cin >> h >> w;
	}


	return 0;
}