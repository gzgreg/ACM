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

	int T; cin >> T;
	for(int id = 1; id <= T; id++) {
		cout << "Case #" << id << ": ";

		int R, C, H, V; cin >> R >> C >> H >> V;

		vector<string> waffle;
		for(int i = 0; i < R; i++) {
			string cur; cin >> cur; waffle.push_back(cur);
		}

		int totalChips = 0;
		for(string cur : waffle) {
			for(char val : cur) {
				totalChips += (val == '@');
			}
		}
		if(totalChips == 0) {
			cout << "POSSIBLE" << endl;
			continue;
		}
		int chipsPerRow = totalChips / (H+1);
		int chipsPerCell = totalChips / (H+1) / (V+1);

		if(chipsPerCell * (H+1) * (V+1) != totalChips) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}

		vector<int> cuts;
		int curChips = 0;
		bool good = true;
		for(int i = 0; i < R; i++) {
			for(char val : waffle[i]) {
				curChips += (val == '@');
			}
			if(curChips == chipsPerRow) {
				curChips = 0;
				cuts.push_back(i+1);
			} else if (curChips > chipsPerRow) {
				cout << "IMPOSSIBLE" << endl;
				good = false;
				break;
			}
		}
		if(!good) continue;
		vector<int> curChipCells (H+1, 0);

		for(int i = 0; i < C; i++) {
			int cutsId = 0;
			for(int j = 0; j < R; j++) {
				if(cuts[cutsId] == j) cutsId++;
				curChipCells[cutsId] += (waffle[j][i] == '@');
			}

			int numLessOrEqual = 0;
			int numEqual = 0;
			for(auto val : curChipCells) {
				//cout << val << " ";
				if(val <= chipsPerCell) {
					numLessOrEqual++;
				}
				if(val == chipsPerCell) numEqual++;
			}
			//cout << endl;
			if(numEqual == H+1) {
				curChipCells = vector<int>(H+1, 0);
			} else if (numLessOrEqual != H+1) {
				cout << "IMPOSSIBLE" << endl;
				good = false;
				break;
			}
		}
		if(!good) continue;
		cout << "POSSIBLE" << endl;
	}
	
	return 0;
}