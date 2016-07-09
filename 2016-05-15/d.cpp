#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

vector<int> chroot(vector<set<int>> edgeList, int root){
	vector<int> ret(edgeList.size(), -1);

	queue<int> bfsq; bfsq.push(root);
	ret[root] = root;
	while(!bfsq.empty()){
		int curr = bfsq.front(); bfsq.pop();
		for(int val : edgeList[curr]){
			if(val != ret[curr] && val != curr){
				ret[val] = curr;
				bfsq.push(val);
			}
		}
	}

	return ret;
}

int main(){
	freopen("dynamic.in", "r", stdin);
	freopen("dynamic.out", "w", stdout);

	int n; cin >> n;

	while(n != 0){
		vector<set<int>> edgeList (n, set<int>());

		for(int i = 0; i < n-1; i++){
			int a, b; cin >> a >> b;
			edgeList[a-1].insert(b-1);
			edgeList[b-1].insert(a-1);
		}

		vector<int> parent = chroot(edgeList, 0);
		int m; cin >> m;

		for(int i = 0; i < m; i++){
			string s; cin >> s;
			if(s == "!"){
				int u; cin >> u;
				parent = chroot(edgeList, u-1);
			} else {
				int u, v; cin >> u >> v;
				u--; v--;
				set<int> seen;
				while(true){
					if(seen.find(u) != seen.end()){
						cout << u+1 << endl;
						break;
					} else {
						seen.insert(u);
						u = parent[u];
					}
					if(seen.find(v) != seen.end()){
						cout << v+1 << endl;
						break;
					} else {
						seen.insert(v);
						v = parent[v];
					}
				}
			}
		}

		cin >> n;
	}

	return 0;
}