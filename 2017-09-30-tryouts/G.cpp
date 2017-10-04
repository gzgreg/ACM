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

	int n; cin >> n;

	vector<int> vals(n);
	int totBad = 0;
	for(int i = 0; i < n; i++) {
		cin >> vals[i];
		totBad += vals[i];
	}

	vector<int> par(n, -1);
	vector<set<int>> child(n);
	set<int> leaf;
	set<int> root;
	for(int i = 0; i < n; i++) {
		leaf.insert(i);
		root.insert(i);
	}
	for(int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		par[b] = a;
		child[a].insert(b);
		leaf.erase(a);
		root.erase(b);
	}

	if(totBad == 0) {
		cout << 0 << endl;
		return 0;
	}

	vector<set<int>> levels;
	set<int> curLevel (root);

	while(!curLevel.empty()) {
		levels.push_back(curLevel);
		set<int> nextLevel;
		for(int cur : curLevel) {
			for(int j : child[cur]) {
				nextLevel.insert(j);
			}
			cout << cur << " ";
		}
		
	cout << endl;
		curLevel = nextLevel;
	}

	int ans = 0;
	for(int i = 1 << 30; i > 0; i >>= 1) {
		vector<int> curVal(vals);
		int curAns = ans + i;
		for(int i = levels.size() - 1; i > 0; i--) {
			for(int cur : levels[i]) {
				int toMove = 0;
				if(child[cur].size() > 0) {
					for(int j : child[cur]) {
						toMove = max(toMove, curVal[j] - curAns);
					}
					for(int j : child[cur]) {
						toMove = min(toMove, curVal[j]);
					}
					for(int j : child[cur]) {
						curVal[j] -= toMove;
					}
					curVal[cur] = toMove;
				}
			}
		}

		for(int i = 0; i < n; i++) {
			if(curVal[i] > curAns) {
				ans = curAns;
				break;
			}
		}
		cout << curAns << endl;
		for(int i = 0; i < n; i++) {
			cout << curVal[i] << " ";
		}
		cout << endl;
	}

	cout << ans + 1 << endl;
	
	return 0;
}