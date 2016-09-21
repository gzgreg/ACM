#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

vector<vector<int>> boxes;

int dfs (set<int> boxesLeft, pair<int, int> base) {
	if(boxesLeft.size() == 0) {
		return 1;
	}
	int best = 0;
	for(int box : boxesLeft) {
		set<int> copy = boxesLeft;
		vector<int> boxDims = boxes[box];
		copy.erase(box);
		if((base.first >= boxDims[0] && base.second >= boxDims[1])
			|| (base.second >= boxDims[0] && base.first >= boxDims[1])) {
			best = max(best, dfs(copy, {boxDims[0], boxDims[1]}));
		}
		if((base.first >= boxDims[0] && base.second >= boxDims[2])
			|| (base.second >= boxDims[0] && base.first >= boxDims[2])) {
			best = max(best, dfs(copy, {boxDims[0], boxDims[2]}));
		}
		if((base.first >= boxDims[2] && base.second >= boxDims[1])
			|| (base.second >= boxDims[2] && base.first >= boxDims[1])) {
			best = max(best, dfs(copy, {boxDims[1], boxDims[2]}));
		}
	}
	return best+1;
}

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;
	int idx = 1;

	while(n != 0) {
		for(int i = 0; i < n; i++) {
			int x, y, z; cin >> x >> y >> z;
			boxes.push_back({x, y, z});
		}

		set<int> initial;
		for(int i = 0; i < n; i++) {
			initial.insert(i);
		}

		int ans = dfs(initial, {50, 50});
		cout << "Case " << idx << ": " << ans-1 << endl;
		idx++;
		cin >> n;
		boxes.clear();
	}
	
	return 0;
}