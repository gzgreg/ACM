#include <bits/stdtr1c++.h>

using namespace std;

int main(){
	int T; cin >> T;
	for(int i = 0; i < T; i++){
		int k, w, h; cin >> k >> w >> h;
		map<char, int> classDict;
		vector<vector<int> > grid (h);

		for(int j = 0; j < k; j++){
			char label; cin >> label;
			int t; cin >> t;
			classDict.insert(make_pair(label, t));
		}
		int startH, startW;
		map<pair<int, int>, long long> weights;
		for(int j = 0; j < h; j++){
			string currS; cin >> currS;
			grid[j] = vector<int> (w);
			for(int l = 0; l < w; l++){
				char curr = currS[l];
				grid[j][l] = classDict[curr];
				if(curr == 'E'){
					startH = j;
					startW = l;
					weights.insert(make_pair(make_pair(j, l), 0));
				} else {
					weights.insert(make_pair(make_pair(j, l), 500e8));
				}
			}
		}

		set<pair<long long, pair<int, int> > > toVisit;
		toVisit.insert(make_pair(0, make_pair(startH, startW)));
		while(!toVisit.empty()){
			pair<int, pair<int, int> > currP = *toVisit.begin(); toVisit.erase(toVisit.begin());
			pair<int, int> curr = currP.second;
			int hCurr = curr.first;
			int wCurr = curr.second;
			for(int j= -1; j <= 1; j += 2){
				if(hCurr + j < 0 || hCurr + j >= h) continue;
				pair<int, int> edge = make_pair(hCurr+j, wCurr);
				long long weight = weights.at(edge);
				if(weight > weights.at(curr) + grid[hCurr + j][wCurr]){
					weights.at(edge) = weights.at(curr) + grid[hCurr + j][wCurr];
					toVisit.insert(make_pair(weight, edge));
				}
			}
			for(int j= -1; j <= 1; j += 2){
				if(wCurr + j < 0 || wCurr + j >= w) continue;
				pair<int, int> edge = make_pair(hCurr, wCurr+j);
				long long weight = weights.at(edge);
				if(weight > weights.at(curr) + grid[hCurr][j + wCurr]){
					weights.at(edge) = weights.at(curr) + grid[hCurr][j + wCurr];
					toVisit.insert(make_pair(weight, edge));
				}
			}
		}
		long long currMin = 300e8;
		int currH = 0;
		for(int currW = 0; currW < w; currW++){
			if(weights.at(make_pair(currH, currW)) < currMin){
				currMin = weights.at(make_pair(currH, currW));
			}
		}
		currH = h-1;
		for(int currW = 0; currW < w; currW++){
			if(weights.at(make_pair(currH, currW)) < currMin){
				currMin = weights.at(make_pair(currH, currW));
			}
		}

		int currW = 0;
		for(int currH = 1; currH < h-1; currH++){
			if(weights.at(make_pair(currH, currW)) < currMin){
				currMin = weights.at(make_pair(currH, currW));
			}
		}

		currW = w - 1;
		for(int currH = 1; currH < h-1; currH++){
			if(weights.at(make_pair(currH, currW)) < currMin){
				currMin = weights.at(make_pair(currH, currW));
			}
		}

		cout << currMin << endl;

	}
	return 0;
}