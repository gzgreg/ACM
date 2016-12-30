#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;
	map<int, int> graph;
	map<int, pii> data;
	set<int> unknowns;

	for(int i = 1; i <= n; i++) {
		string vert, cycle; cin >> vert >> cycle;
		int vertint, cycleint;
		if(vert == "?") {
			vertint = -1;
		} else {
			vertint = atoi(vert.c_str());
		}

		if(cycle == "?") {
			cycleint = -1;
		} else {
			cycleint = atoi(cycle.c_str());
		}

		if(vertint == -1 && cycleint == -1) {
			unknowns.insert(i);
		} else {
			data[i] = {vertint, cycleint};
		}
	}

	map<int, pii> origData (data);

	map<int, vector<int>> cycles;
	for(pair<int, pii> vertex : origData) {
		if(vertex.second.second != -1 && vertex.second.first == 0) {
			cycles[vertex.second.second].push_back(vertex.first);
			data.erase(vertex.first);
		}
	}
	origData = data;

	for(pair<int, vector<int>> cycle : cycles) {
		int cycleSize = cycle.first;
		vector<int> vert = cycle.second;
		if(vert.size() % cycleSize != 0) {
			int numLeft = cycleSize - (vert.size() % cycleSize);
			for(pair<int, pii> vertex : origData) {
				if(vertex.second.second == cycleSize
					&& vertex.second.first == -1) {
					vert.push_back(vertex.first);
					data.erase(vertex.first);
					numLeft--;
					if(numLeft == 0) {
						break;
					}
				}
			}
			origData = data;
			if(numLeft != 0) {
				if(unknowns.size() < numLeft) {
					cout << -1 << endl;
					return 0;
				}
				set<int> tmp (unknowns);
				for(int i : tmp) {
					vert.push_back(i);
					unknowns.erase(i);
					numLeft--;
					if(numLeft == 0) break;
				}
			}
		}
		for(int i = 0; i < vert.size() / cycleSize; i++) {
			for(int j = i*cycleSize; j < (i+1)*cycleSize; j++) {
				if(j == i*cycleSize) {
					graph[vert[j]] = vert[(i+1) * cycleSize - 1];
				} else {
					graph[vert[j]] = vert[j-1];
				}
			}
		}
	}

	while(!data.empty()) {
		int maxIdx = -1;
		for(pair<int, pii> vertex : origData) {
			if(vertex.second.first != -1 && vertex.second.second != -1) {
				if(maxIdx == -1 || vertex.second.first > data[maxIdx].first) {
					maxIdx = vertex.first;
				}
			}
		}
		if(maxIdx == -1) {
			//figure this shit out
			//all things have only distance from a cycle
		} else {
			int currCycle = data[maxIdx].second;
			int currDist = data[maxIdx].first;
			int currIdx = maxIdx;
			data.erase(maxIdx);
			while(currDist != 1) {
				origData = data;
				bool found = false;
				for(pair<int, pii> vertex : origData) {
					if(vertex.second.first == currDist - 1
						&& vertex.second.first == currCycle) {
						graph[currIdx] = vertex.first;
						data.erase(currIdx);
						currDist--;
						found = true;
						currIdx = vertex.first;
						break;
					}
				}
				if(found) continue;
				for(pair<int, pii> vertex : origData) {
					if(vertex.second.first == currDist - 1) {
						graph[currIdx] = vertex.first;
						data.erase(currIdx);
						currDist--;
						found = true;
						currIdx = vertex.first;
						break;
					}
				}
				if(found) continue;
				if(unknowns.size() == 0) {
					cout << -1 << endl;
					return 0;
				}
				graph[currIdx] = *(unknowns.begin());
				currIdx = graph[currIdx];
				unknowns.erase(currIdx);
				currDist--;
			}
			if(cycles[currCycle].size() > 0) {
				graph[currIdx] = cycles[currCycle][0];
			} else {
				//create new cycle with right size
				if(unknowns.size() < currCycle) {
					cout << -1 << endl;
					return 0;
				}
				vector<int> vert;
				set<int> tmp (unknowns);
				int numLeft = currCycle;
				for(int i : tmp) {
					vert.push_back(i);
					unknowns.erase(i);
					numLeft--;
					if(numLeft == 0) break;
				}
				for(int j = 0; j < currCycle; j++) {
					if(j == 0) {
						graph[vert[j]] = vert[currCycle - 1];
					} else {
						graph[vert[j]] = vert[j-1];
					}
				}
				graph[currIdx] = vert[0];
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		cout << graph[i] << " ";
	}
	cout << endl;
	
	return 0;
}