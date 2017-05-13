#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	
	int n; int id = 0;
	while(cin >> n) {
		id++;
		vector<vector<int>> stacks;
		for(int i = 0; i < n; i++) {
			int h; cin >> h;
			vector<int> stack;
			for(int j = 0; j < h; j++) {
				int curr; cin >> curr; stack.push_back(curr);
			}
			stacks.push_back(stack);
		}

		vector<int> indices(n, 0);
		int bestSplits = 1e8;
		for(int asdf = 0; asdf < n; asdf++) {
			for(int lastIndex = 0; lastIndex < n; lastIndex++) {
				indices = vector<int>(n, 0);
				int currIndex = asdf;
				int splits = 0;
				while(true) {
					bool currIsMin = false;
					int minVal = 1e6;
					int minIdx = 0;
					for(int i = 0; i < n; i++) {
						int curr = indices[i];
						if(curr == stacks[i].size()) continue;
						if(stacks[i][curr] < minVal) {
							minIdx = i;
							minVal = stacks[i][curr];
							if(currIsMin && i != currIndex) {
								currIsMin = false;
							}
							if(i == currIndex) {
								currIsMin = true;
							}
						} else if (stacks[i][curr] == minVal) {
							if(i == currIndex) {
								currIsMin = true;
							}
							if(minIdx == lastIndex) {
								minIdx = i;
							}
						}
					}

					if(currIsMin) {
						indices[currIndex]++;
					} else {
						if(indices[currIndex] != stacks[currIndex].size()) splits++;
						indices[minIdx]++;
						currIndex = minIdx;
					}
					// cout << currIndex << " " << splits << " " << minVal << endl;

					if(minVal == 1e6) break;
				}
				// cout << asdf << " " << splits << endl;
				bestSplits = min(splits, bestSplits);
			}
		}
		
		cout << "Case " << id << ": " << (2*bestSplits + n - 1) << endl;
	}

	return 0;
}