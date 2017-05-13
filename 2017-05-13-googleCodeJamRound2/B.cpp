#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	for(int id = 1; id <= T; id++) {
		int N, C, M; cin >> N >> C >> M;
		
		vector<map<int, int>> pos (N, map<int, int>());
		for(int i = 0; i < M; i++) {
			int a, j; cin >> a >> j; pos[a-1][j-1]++;
		}

		vector<set<int>> trainPos;
		vector<set<int>> trainPeople;
		int proms = 0;
		for(int i = 0; i < N; i++) {
			for(pii currPos : pos[i]) {
				if(currPos.second == 0) continue;
				// cout << i << " " << currPos.first << " " << currPos.second << endl;
				
				for(int asdf = 0; asdf < currPos.second; asdf++) {
					bool placed = false;
					for(int j = 0; j < trainPos.size(); j++) {
						if(trainPeople[j].count(currPos.first)) {
							continue;
						}
						if(!trainPos[j].count(i)) {
							trainPeople[j].insert(currPos.first);
							trainPos[j].insert(i);
							pos[i][currPos.first]--;
							placed = true;
							// cout << "asdfasdf" << endl;
							break;
						}
					}
					if(!placed && i != 0) {
						for(int j = 0; j < trainPos.size(); j++) {
							if(trainPeople[j].count(currPos.first)){
								continue;
							}
							for(int k : trainPos[j]) {
								if(k > i) break;
								if(k != 0 && !trainPos[j].count(k-1)) {
									proms++;
									trainPeople[j].insert(currPos.first);
									trainPos[j].insert(k-1);
									placed = true;
									// cout << "aaa" << endl;
									break;
								}
							}
							if(placed) break;
						}
					}
					if(!placed) {
						// cout << "asdf" << endl;
						trainPos.push_back({i});
						trainPeople.push_back({currPos.first});
					}
				}
				
			}
		}
		cout << "Case #" << id << ": ";
		cout << trainPos.size() << " " << proms << endl;
		
		// int numTix = M;
		// vector<vector<pii>> trains;
		// vector<set<int>> people;
		// while(numTix > 0) {
		// 	vector<pii> newTrain;
		// 	set<int> newPeople;
		// 	for(int i = 0; i < N; i++) {
		// 		for(pii curr : pos[i]) {
		// 			if(numTix == 0) break;
		// 			if(curr.second > 0 
		// 				&& !newPeople.count(curr.first)) {
		// 				pos[i][curr.first]--;
		// 				newPeople.insert(curr.first);
		// 				numTix--;
		// 				newTrain.push_back({i, curr.first})
		// 			}
		// 		}
		// 	}
		// 	trains.push_back(newTrain);
		// 	people.push_back(newPeople);
		// }

		// int numTrains = trains.size();
		// int proms = 0;
		// for(int i = numTrains - 1; i > 0; i--) {
		// 	int currProms = 0;
		// 	for(pii curr : trains[i]) {
		// 		for(int)
		// 	}
		// }
	}
	
	return 0;
}