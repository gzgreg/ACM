#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	int n, m; cin >> n >> m;
	vector<set<int>> pairs (n);
	for(int i = 0; i < m ; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		pairs[a].insert(b);
		pairs[b].insert(a);
	}

	int numRoots = 0;
	vector<int> ids;
	for(int i = 0; i < n; i++) {
		set<int> vals;
		for(int j : pairs[i]) {
			if(j >= i) break;
			vals.insert(ids[j]);
		}
		int idx = 0;
		while(vals.count(idx)) {
			idx++;
		}
		ids.push_back(idx);
		numRoots = max(numRoots, idx);
	}

	cout << numRoots + 1 << endl;
	for(int i = 0; i < n; i++) {
		cout << ids[i] + 1 << " ";
	}
	cout << endl;
	
	return 0;
}