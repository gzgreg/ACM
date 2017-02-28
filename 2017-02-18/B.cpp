#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;

	queue<string> players;

	string WO, WD, BO, BD;

	cin >> WO >> BO >> WD >> BD;

	for(int i = 0; i < n - 4; i++) {
		string curr; cin >> curr; players.push(curr);
	}

	string seq; cin >> seq;

	int maxDyn = 0, currDyn = 0;
	bool white = false;
	bool firstW = true, firstB = true;
	vector<pair<string, string>> pairs;

	for(char i : seq) {
		if(white) {
			if(i == 'W') {
				currDyn++;
				players.push(BD);
				BD = BO;
				BO = players.front(); players.pop();
				if(currDyn > maxDyn) {
					maxDyn = currDyn;
					pairs.clear();
					if(firstW) {
						pairs.push_back({WO, WD});
					} else {
						pairs.push_back({WD, WO});
					}
				} else if (currDyn == maxDyn) {
					if(firstW) {
						pairs.push_back({WO, WD});
					} else {
						pairs.push_back({WD, WO});
					}
				}
			} else {
				currDyn = 1;
				white = false;
				players.push(WD);
				WD = WO;
				WO = players.front(); players.pop();
				if(currDyn > maxDyn) {
					maxDyn = currDyn;
					pairs.clear();
					if(firstB) {
						pairs.push_back({BO, BD});
					} else {
						pairs.push_back({BD, BO});
					}
				} else if (currDyn == maxDyn) {
					if(firstB) {
						pairs.push_back({BO, BD});
					} else {
						pairs.push_back({BD, BO});
					}
				}
			}
		} else {
			if(i == 'W') {
				currDyn = 1;
				white = true;
				players.push(BD);
				BD = BO;
				BO = players.front(); players.pop();
				if(currDyn > maxDyn) {
					maxDyn = currDyn;
					pairs.clear();
					if(firstW) {
						pairs.push_back({WO, WD});
					} else {
						pairs.push_back({WD, WO});
					}
				} else if (currDyn == maxDyn) {
					if(firstW) {
						pairs.push_back({WO, WD});
					} else {
						pairs.push_back({WD, WO});
					}
				}
			} else {
				currDyn++;
				players.push(WD);
				WD = WO;
				WO = players.front(); players.pop();
				if(currDyn > maxDyn) {
					maxDyn = currDyn;
					pairs.clear();
					if(firstB) {
						pairs.push_back({BO, BD});
					} else {
						pairs.push_back({BD, BO});
					}
				} else if (currDyn == maxDyn) {
					if(firstB) {
						pairs.push_back({BO, BD});
					} else {
						pairs.push_back({BD, BO});
					}
				}
			}
		}
		if(i == 'W') {
			string tmp = WO;
			WO = WD;
			WD = tmp;
			firstW = !firstW;
			firstB = false;
		} else {
			string tmp = BO;
			BO = BD;
			BD = tmp;
			firstB = !firstB;
			firstW = false;
		}
	}

	for(pair<string, string> curr : pairs) {
		cout << curr.first << " " << curr.second << endl;
	}
	
	return 0;
}