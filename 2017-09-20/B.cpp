#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;
	n--;
	vector<pii> floors;
	for(int i = 0; i < m; i++) {
		int ki, fi; cin >> ki >> fi;
		ki--; fi--;
		floors.emplace_back(ki, fi);
	}

	sort(floors.begin(), floors.end());

	for(pii cur : floors) {
		if(cur.first == n) {
			cout << cur.second + 1 << endl;
			return 0;
		}
	}

	int valid = -19203847;
	bool validFound = false;

	for(int i = 1; i < 101; i++) {
		bool curValid = true;
		for(pii cur : floors) {
			if(cur.first < cur.second * i || cur.first >= (cur.second+1) * i) {
				curValid = false;
				break;
			}
		}
		if(curValid) {
			int curFloor = n / i;
			if(validFound) {
				if(valid != curFloor) {
					cout << -1 << endl;
					return 0;
				}
			} else {
				validFound = true;
				valid = curFloor;				
			}
		}
	}

	cout << valid + 1 << endl;
	
	return 0;
}