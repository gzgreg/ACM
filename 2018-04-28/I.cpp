#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> par;

int query(int n1, int n2) {
	cout << "? " << n1 + 1 << " " << n2 + 1 << endl;
	int cur; cin >> cur; return cur;
}

int findRoot(set<int> vertices, int leaf1, int leaf2, int depth) {
	if(depth == 2) {
		vertices.erase(leaf1);
		vertices.erase(leaf2);

		int root = *vertices.begin();
		par[leaf1] = root;
		par[leaf2] = root;
		return root;
	}
	set<int> set1, set2;
	int root;
	int newLeaf1, newLeaf2;
	for(auto cur : vertices) {
		if(cur == leaf1) {
			set1.insert(cur);
			continue;
		}
		if(cur == leaf2) {
			set2.insert(cur);
			continue;
		}
		int dist1 = query(leaf1, cur);
		int dist2 = query(leaf2, cur);
		if(dist1 == dist2) {
			root = cur;
		} else if (dist1 < dist2) {
			set1.insert(cur);
			if(dist1 == 2 * (depth - 2)) newLeaf1 = cur;
		} else {
			set2.insert(cur);
			if(dist2 == 2*(depth - 2)) newLeaf2 = cur;
		}
	}

	int nextRoot1 = findRoot(set1, leaf1, newLeaf1, depth - 1);
	int nextRoot2 = findRoot(set2, leaf2, newLeaf2, depth - 1);
	par[nextRoot1] = root;
	par[nextRoot2] = root;
	return root;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	if(n == 1) {
		cout << "! 0" << endl;
		return 0;
	}
	int h = 0;

	par = vector<int>(n, -2);
	set<int> initVertices;
	for(int i = 0; i < n; i++) {
		initVertices.insert(i);
	}

	for(int i = n; i > 0; i >>= 1) {
		h++;
	}

	set<pii> triedLeaves;

	int h1, h2;
	int dist = 0;

	while(dist != 2*(h - 1)) {
		h1 = rand() % n;
		h2 = rand() % n;

		if(h1 == h2) continue;
		if(triedLeaves.count({h1, h2})) continue;
		triedLeaves.insert({h1, h2});
		triedLeaves.insert({h2, h1});

		dist = query(h1, h2);
	}

	par[findRoot(initVertices, h1, h2, h)] = -1;
	cout << "! ";
	for(auto cur : par) {
		cout << cur + 1 << " ";
	}
	cout << endl;

	
	return 0;
}