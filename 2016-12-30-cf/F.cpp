#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int h; cin >> h;

	vector<int> path;
	map<int, vector<int>> tree;
	int nextNum = 1;
	while(true) {
		cout << "? " << nextNum << endl;
		path.push_back(nextNum);

		int con; cin >> con;
		vector<int> verts;
		for(int i = 0; i < con; i++) {
			int curr; cin >> curr; verts.push_back(curr);
		}

		tree[nextNum] = verts;
		if(con == 2) {
			cout << "! " << nextNum << endl;
			return;
		} else if (con == 1) {
			int root = path[0];
			nextNum = !tree.count(tree[root][0]) ? 
					tree[root][0] : tree[root][1];
			break;
		} else {
			nextNum = !tree.count(verts[0]) ? verts[0] : verts[1]; 
		}
	}
	while(true) {
		cout << "? " << nextNum << endl;
		path.insert(path.begin(), nextNum);

		int con; cin >> con;
		vector<int> verts;
		for(int i = 0; i < con; i++) {
			int curr; cin >> curr; verts.push_back(curr);
		}

		tree[nextNum] = verts;
		if(con == 2) {
			cout << "! " << nextNum << endl;
			return;
		} else if (con == 1) {
			nextNum = verts[0];
			break;
		} else {
			nextNum = !tree.count(verts[0]) ? verts[0] : verts[1]; 
		}
	}

	int currHeight = (path.size() + 1) / 2;
	int root = path[currHeight - 1];

	while(currHeight < h-3) {
		path = vector<int> (path.begin(), path.begin() + currHeight);
		nextNum = tree.count(tree[root][0]) ? 
					tree.count(tree[root][1]) ? tree[root][2] : tree[root][1]
					: tree[root][0];
		while(true) {
			path.push_back(nextNum);
			if(path.size() == 7) break;
			cout << "? " << nextNum << endl;

			int con; cin >> con;
			vector<int> verts;
			for(int i = 0; i < con; i++) {
				int curr; cin >> curr; verts.push_back(curr);
			}

			tree[nextNum] = verts;
			if(con == 2) {
				cout << "! " << nextNum << endl;
				return;
			} else if (con == 1) {
				nextNum = verts[0];
				break;
			} else {
				nextNum = !tree.count(verts[0]) ? verts[0] : verts[1]; 
			}
		}
		currHeight = (path.size() + 1) / 2;
		root = path[currHeight - 1];
	}
	//root of tree is near root
	queue<int> bfsq;
	nextNum = tree.count(tree[root][0]) ? 
					tree.count(tree[root][1]) ? tree[root][2] : tree[root][1]
					: tree[root][0];
	bfsq.push(nextNum);
	for(int i = 0; i < 6 && !bfsq.empty(); i++) {
		int currCheck = bfsq.front(); bfsq.pop();
		// if(!tree.count(currCheck)) {
			cout << "? " << currCheck << endl;
			int con; cin >> con;
			vector<int> verts;
			for(int j = 0; j < con; j++) {
				int curr; cin >> curr; verts.push_back(curr);
			}
			tree[currCheck] = verts;
			if(con == 2) {
				cout << "! " << currCheck << endl;
				return;
			}
			for(int j : verts) {
				if(!tree.count(j)) bfsq.push(j);
			}
		// } else {
		// 	vector<int> verts = tree[currCheck];
		// 	for(int j : verts) {
		// 		bfsq.push(j);
		// 	}
		// }
	}
	int trueRoot = bfsq.front();
	cout << "! " << trueRoot << endl;
	return;
}

int main(){
	ios::sync_with_stdio(0);

	int t; cin >> t;
	while(t--) {
		solve();
		
	}
	
	return 0;
}