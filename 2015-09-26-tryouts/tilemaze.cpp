using namespace std;

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>
#include <queue>

int main(){
	int R, C;
	cin >> R >> C;
	while(R != 0 || C != 0){
		queue<vector<int> > bfsq;
		char grid[R][C];
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				cin >> grid[i][j];
			}
		}
		int dir;
		int corner[2];
		for(int i = 0; i < R; i++){
			bool found = false;
			for(int j = 0; j < C; j++){
				if(grid[i][j] == 'S'){
					found = true;
					if(grid[i][j+1] == 'S' && j != C-1){
						corner[0] = i; corner[1] = j;
						if(grid[i+1][j] == 'S') dir = 1; // ..
														 //	. 
						else if(grid[i+1][j+1] == 'S') dir = 2; // ..
																//  .
					} else {
						if(grid[i+1][j+1] == 'S'){
							corner[0] = i; corner[1] = j; dir = 4;
						}
						else{
							corner[0] = i; corner[1] = j-1; dir = 3;
						}
					}
					break;
				}
			}
			if(found) break;
		}
		vector<int> init;
		init.push_back(corner[0]); init.push_back(corner[1]); init.push_back(dir); init.push_back(0);
		bfsq.push(init);
		int numSteps = -1;
		bool visited[2000];
		fill_n(visited, 2000, false);
		while(!bfsq.empty()){
			vector<int> curr = bfsq.front();
			bfsq.pop();
			int row = curr[0], col = curr[1], dir = curr[2], steps = curr[3];
			int hash = row + col*21 + (dir-1)*442;
			if(visited[hash]){
				continue;
			} else {
				visited[hash] = true;
			}
			if(row < 0 || col < 0 || row > R - 2 || col > C-2) continue;
			if(dir == 1){
				if(grid[row][col] == 'X' || grid[row][col+1] == 'X' || grid[row+1][col] == 'X') continue;
				else if(grid[row][col] == 'E' && grid[row][col+1] == 'E' && grid[row+1][col] == 'E'){
					numSteps = steps;
					break;
				}
			} else if(dir == 2){
				if(grid[row][col] == 'X' || grid[row][col+1] == 'X' || grid[row+1][col+1] == 'X') continue;
				else if(grid[row][col] == 'E' && grid[row][col+1] == 'E' && grid[row+1][col+1] == 'E'){
					numSteps = steps;
					break;
				}
			} else if(dir == 3){
				if(grid[row+1][col] == 'X' || grid[row][col+1] == 'X' || grid[row+1][col+1] == 'X') continue;
				else if(grid[row+1][col] == 'E' && grid[row][col+1] == 'E' && grid[row+1][col+1] == 'E'){
					numSteps = steps;
					break;
				}
			} else if(dir == 4){
				if(grid[row][col] == 'X' || grid[row+1][col] == 'X' || grid[row+1][col+1] == 'X') continue;
				else if(grid[row][col] == 'E' && grid[row+1][col] == 'E' && grid[row+1][col+1] == 'E'){
					numSteps = steps;
					break;
				}
			}
			vector<int> another; another = curr; another[2]++; if(another[2] == 5) another[2] = 1; another[3]++; bfsq.push(another);
			another = curr; another[2]--; if(another[2] == 0) another[2] = 4; another[3]++; bfsq.push(another);

			another = curr; another[0]--; another[3]++; bfsq.push(another);
			another = curr; another[0]++; another[3]++; bfsq.push(another);
			another = curr; another[1]--; another[3]++; bfsq.push(another);
			another = curr; another[1]++; another[3]++; bfsq.push(another);
			// cout << corner[0] << " " << corner[1] << " " << dir << " " << steps << endl;
			// string junk; getline(cin, junk);
		}

		if(numSteps == -1){
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << numSteps << endl;
		}

		cin >> R >> C;
	}
	return 0;
}