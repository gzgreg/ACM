#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<vector<bool> > garden;
	vector<bool> templ (10001, false);
	for(int i = 0; i < 10001; i++){
		garden.push_back(templ);
	}
	vector<pair<int, int> > goblins;
	int g; cin >> g;
	for(int i = 0; i < g; i++){
		int x, y; cin >> x >> y;
		goblins.push_back(make_pair(x, y));
	}
	int m; cin >> m;
	for(int i = 0; i < m; i++){
		int x, y, r; cin >> x >> y >> r;
		for(int j = max(0, x-r-1); j < min(10000, x+r+1); j++){
			for(int k = max(0, y-r-1); k < min(10000, y+r+1); k++){
				if((j-x) * (j-x) + (k-y) * (k-y) <= r*r){
					garden[j][k] = true;
				}
			}
		}
	}
	// for(int i = 0; i <= 10; i++){
	// 	for(int j = 0; j <= 10; j++){
	// 		cout << garden[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	int numGobs = 0;
	for(int i = 0; i < g; i++){
		if(!garden[goblins[i].first][goblins[i].second]) numGobs++;
	}
	cout << numGobs;
	return 0;
}