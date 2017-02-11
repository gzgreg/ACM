#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

unordered_map<string, string> ds;
unordered_map<string, int> dsrank;

string find(string s) {
	if(ds[s] != s) {
		ds[s] = find(ds[s]);
	}
	return ds[s];
}

void merge(string x, string y) {
	string xRoot = find(x);
	string yRoot = find(y);

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

	int n, m, q; cin >> n >> m >> q;

	for(int i = 0; i < n; i++) {
		string curr; cin >> curr; ds[curr] = curr; dsrank[curr] = 0;
		ds[curr + "["] = curr + "["; dsrank[curr + "["] = 0;
	}

	for(int i = 0; i < m; i++) {
		string xi, yi; int t; cin >> t >> xi >> yi;
		if(t == 1) {
			if(find(xi + "[") == find(yi)) {
				cout << "NO" << endl;
			} else {
				cout << "YES" << endl;
				merge(xi + "[", yi + "[");
				merge(xi, yi);
			}
		} else {
			if(find(xi) == find(yi)) {
				cout << "NO" << endl;
			} else {
				cout << "YES" << endl;

				merge(xi + "[", yi);
				merge(yi + "[", xi);
			}
		}
	}

	for(int i = 0; i < q; i++) {
		string xi, yi; cin >> xi >> yi;

		if(find(xi) == find(yi)) {
			cout << 1 << endl;
		} else if (find(xi + "[") == find(yi)) {
			cout << 2 << endl;
		} else {
			cout << 3 << endl;
		}
	}
	
	return 0;
}