#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	
	int T; cin >> T;
	while(T--) {
		int X, Y, H1, H2; cin >> X >> Y >> H1 >> H2;
		vector<vector<int>> cannons1;
		vector<vector<int>> cannons2;
		for(int i = 0; i < X; i++) {
			int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
			cannons1.push_back({a, b, c, d, e});
		}
		for(int i = 0; i < Y; i++) {
			int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
			cannons2.push_back({a, b, c, d, e});
		}

		priority_queue<pair<int, int>> fire1, fire2;
		priority_queue<pair<int, pair<int, bool>>> charge;

		for(int i = 0; i < cannons1.size(); i++) {
			charge.push({cannons1[i][1], {i, true}});
		}

		for(int i = 0; i < cannons2.size(); i++) {
			charge.push({cannons2[i][1], {i, false}});
		}
		int currTime = 0;
		while(H1 > 0 || H2 > 0) {
			cout << currTime << " " << fire1.size() << " " << fire2.size() << " " << charge.size() << endl;
			if(!charge.empty()) {
				if((fire1.empty() || fire1.top().first >= charge.top().first)
					&& (fire2.empty() || fire2.top().first >= charge.top().first)) {
					pair<int, pair<int, bool>> curr = charge.top();
					charge.pop();
					if(curr.second.second) {
						vector<int> cannon = cannons1[curr.second.first];
						fire1.push({curr.first + cannon[2], curr.second.first});
					} else {
						vector<int> cannon = cannons2[curr.second.first];
						fire2.push({curr.first + cannon[2], curr.second.first});
					}
					continue;
				}
			}

			if(!fire1.empty() && !fire2.empty()) {
				if(fire1.top().first < fire2.top().first) {
					pii curr = fire1.top(); fire1.pop();
					currTime = curr.first;
					H2 -= cannons1[curr.second][3];
					if(cannons1[curr.second][0] == 2) {
						while(!fire2.empty()) {
							pair<int, int> old = fire2.top(); fire2.pop();
							charge.push({curr.first + cannons2[old.second][4], {old.second, false}});
						}
					}
					charge.push({curr.first + cannons1[curr.second][4], {curr.second, true}});
				} else if (fire1.top().first > fire2.top().first) {
					pii curr = fire2.top(); fire2.pop();
					currTime = curr.first;
					H1 -= cannons2[curr.second][3];
					if(cannons2[curr.second][0] == 2) {
						while(!fire1.empty()) {
							pair<int, int> old = fire1.top(); fire1.pop();
							charge.push({curr.first + cannons1[old.second][4], {old.second, true}});
						}
					}
					charge.push({curr.first + cannons2[curr.second][4], {curr.second, false}});
				} else {
					currTime = fire1.top().first;
					vector<pair<int, vector<int>>> firing1, firing2;
					while(!fire1.empty() && fire1.top().first == currTime) {
						firing1.push_back({fire1.top().second, cannons1[fire1.top().second]});
						fire1.pop();
					}
					while(!fire2.empty() && fire2.top().first == currTime) {
						firing2.push_back({fire2.top().second, cannons2[fire2.top().second]});
						fire2.pop();
					}
					int totalPow1 = 0, totalPow2 = 0;
					bool isSpecial1 = false, isSpecial2 = false;
					for(pair<int, vector<int>> cannon : firing1) {
						charge.push({currTime + cannon.second[4], {cannon.first, true}});
						totalPow1 += cannon.second[3];
						if(cannon.second[0] == 2) isSpecial1 = true;
					}
					for(pair<int, vector<int>> cannon : firing2) {
						charge.push({currTime + cannon.second[4], {cannon.first, false}});
						totalPow2 += cannon.second[3];
						if(cannon.second[0] == 2) isSpecial2 = true;
					}
					if(totalPow1 > totalPow2) {
						H2 -= totalPow1;
						if(isSpecial1) {
							while(!fire2.empty()) {
								pair<int, int> old = fire2.top(); fire2.pop();
								charge.push({currTime + cannons2[old.second][4], {old.second, false}});
							}
						}
					} else if (totalPow1 < totalPow2) {
						H1 -= totalPow2;
						if(isSpecial2) {
							while(!fire1.empty()) {
								pair<int, int> old = fire1.top(); fire1.pop();
								charge.push({currTime + cannons1[old.second][4], {old.second, true}});
							}
						}
					} else {
						if (H1 >= H2) {
							H2 -= totalPow1;
							if(isSpecial1) {
								while(!fire2.empty()) {
									pair<int, int> old = fire2.top(); fire2.pop();
									charge.push({currTime + cannons2[old.second][4], {old.second, false}});
								}
							}
						} else {
							H1 -= totalPow2;
							if(isSpecial2) {
								while(!fire1.empty()) {
									pair<int, int> old = fire1.top(); fire1.pop();
									charge.push({currTime + cannons1[old.second][4], {old.second, true}});
								}
							}
						}
					}
				}
			} else if (!fire1.empty()) {
				pii curr = fire1.top(); fire1.pop();
				currTime = curr.first;
				H2 -= cannons1[curr.second][3];
				if(cannons1[curr.second][0] == 2) {
					while(!fire2.empty()) {
						pair<int, int> old = fire2.top(); fire2.pop();
						charge.push({curr.first + cannons2[old.second][4], {old.second, false}});
					}
				}
				charge.push({curr.first + cannons1[curr.second][4], {curr.second, true}});
			} else if (!fire2.empty()) {
				pii curr = fire2.top(); fire2.pop();
				currTime = curr.first;
				H1 -= cannons2[curr.second][3];
				if(cannons2[curr.second][0] == 2) {
					while(!fire1.empty()) {
						pair<int, int> old = fire1.top(); fire1.pop();
						charge.push({curr.first + cannons1[old.second][4], {old.second, true}});
					}
				}
				charge.push({curr.first + cannons2[curr.second][4], {curr.second, false}});
			}
		}

		if(H1 > 0) {
			cout << "A" << endl << currTime << endl;
		} else {
			cout << "B" << endl << currTime << endl;
		}

	}

	return 0;
}