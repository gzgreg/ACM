#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> ds;
vector<int> dsrank;

int find(int s) {
	if(ds[s] != s) {
		ds[s] = find(ds[s]);
	}
	return ds[s];
}

void merge(int x, int y) {
	int xRoot = find(x);
	int yRoot = find(y);

	if(xRoot == yRoot) return;

	if(dsrank[xRoot] < dsrank[yRoot]) {
		ds[xRoot] = yRoot;
	} else if (dsrank[xRoot] > dsrank[yRoot]) {
		ds[yRoot] = xRoot;
	} else {
		ds[yRoot] = xRoot;
		dsrank[xRoot]++;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		ds.push_back(i); dsrank.push_back(0);
	}

	vector<int> vals;
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; vals.push_back(cur);
	}

	int k; cin >> k;

	for(int i = 0; i < k; i++) {
		for(int j = 0; j < n; j++) {
			int cur; cin >> cur; merge(j, cur-1);
		}
	}

	int x; cin >> x;
	for(int i = 0; i < n; i++) {
		if(vals[i] == x) {
			if(find(i) == find(0)) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
			return 0;
		}
	}
	
	return 0;
}