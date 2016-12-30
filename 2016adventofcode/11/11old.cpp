#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool canBringToFloor(int id, int floor, vector<set<pair<int, bool>>> floors) {
	bool hasGen = false;
	return floors[floor].count({id, 0});
	for(pair<int, bool> tmp : floors[floor]) {
		if(!tmp.second) {
			hasGen = true;
			if(tmp.first == id) {
				return true;
			}
		}
	}
	return !hasGen;
}

int main(){
	ios::sync_with_stdio(0);

	vector<set<pair<int, bool>>> floors = {{{1, 0}, {1, 1}, {2, 0}, {3, 0}},
												{{2, 1}, {3, 1}},
												{{4, 0}, {4, 1}, {5, 0}, {5, 1}},
												{}};

	queue<pair<pair<int, int>, vector<set<pair<int, bool>>>>> bfsq;

	bfsq.push({{0, 0}, floors});
	map<pair<int, vector<set<pair<int, bool>>>>, pair<int, vector<set<pair<int, bool>>>>> par;

	set<pair<pair<int, vector<int>>, vector<set<pair<int, bool>>>>> visited;

	while(!bfsq.empty()) {
		pair<pair<int, int>, vector<set<pair<int, bool>>>> curr = bfsq.front();
		bfsq.pop();

		vector<set<pair<int, bool>>> noPairs (curr.second);
		vector<int> numPairs (4, 0);
		for(int i = 0; i < 4; i++) {
			set<pair<int, bool>> noPairSub (noPairs[i]);
			set<int> seen;
			for(pair<int, bool> curr : noPairs[i]) {
				if(seen.count(curr.first)) {
					noPairSub.erase({curr.first, 0});
					noPairSub.erase({curr.first, 1});
					numPairs[i]++;
				} else {
					seen.insert(curr.first);
				}
			}
			noPairs[i] = noPairSub;
		}
		if(visited.count({{curr.first.first, numPairs}, noPairs})) continue;
		cout << curr.first.first <<  " " << curr.first.second << endl;
		visited.insert({{curr.first.first, numPairs}, noPairs});
		if(curr.second[3].size() == 10) {
			cout << curr.first.second << endl;
			return 0;
		}
		vector<set<pair<int, bool>>> changed = curr.second;

		bool genAbove = false, genBelow = false;
		if(curr.first.first < 3) {
			for(pair<int, bool> tmp : changed[curr.first.first + 1]) {
				if(!tmp.second) {
					genAbove = true;
					break;
				}
			}
		}
		if(curr.first.first > 0) {
			for(pair<int, bool> tmp : changed[curr.first.first - 1]) {
				if(!tmp.second) {
					genBelow = true;
					break;
				}
			}
		}

		for(pair<int, bool> tmp : changed[curr.first.first]) {
			if(curr.first.first < 3 && (!genAbove || canBringToFloor(tmp.first, curr.first.first + 1, changed))) {
				vector<set<pair<int, bool>>> newState (changed);
				newState[curr.first.first].erase(tmp);
				newState[curr.first.first + 1].insert(tmp);
				bfsq.push({{curr.first.first + 1, curr.first.second + 1}, newState});
			}
			if(curr.first.first > 0 && (!genBelow || canBringToFloor(tmp.first, curr.first.first - 1, changed))) {
				vector<set<pair<int, bool>>> newState (changed);
				newState[curr.first.first].erase(tmp);
				newState[curr.first.first - 1].insert(tmp);
				bfsq.push({{curr.first.first - 1, curr.first.second + 1}, newState});
			}
		}
		int i = 0;
		for(pair<int, bool> tmp : changed[curr.first.first]) {
			int j = 0;
			for(pair<int, bool> tmp2 : changed[curr.first.first]) {
				if(i <= j) continue;
				if(curr.first.first < 3 
					&& (!genAbove
						|| tmp.first == tmp2.first
						|| (canBringToFloor(tmp.first, curr.first.first + 1, changed)
					&& canBringToFloor(tmp2.first, curr.first.first + 1, changed))
					)) {
					vector<set<pair<int, bool>>> newState (changed);
					newState[curr.first.first].erase(tmp);
					newState[curr.first.first + 1].insert(tmp);
					newState[curr.first.first].erase(tmp2);
					newState[curr.first.first + 1].insert(tmp2);
					bfsq.push({{curr.first.first + 1, curr.first.second + 1}, newState});
					}
				j++;
			}
			i++;
		}
	}

							
	return 0;
}