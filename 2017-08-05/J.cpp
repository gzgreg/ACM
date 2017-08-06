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

int lca[20001][20];
int dist[20001][20];
int depth[20001];

vector<pii> adj[20001];

void calcLCA(int node, int par, int d) {
	depth[node] = d;
	for(int j = 1; j < 17; j++) {
		if(lca[node][j-1] != -1) {
			lca[node][j] = lca[lca[node][j-1]][j-1];
			dist[node][j] = min(dist[node][j-1], dist[lca[node][j-1]][j-1]);
		}
	}
	for(pii cur : adj[node]) {
		if(cur.first != par) {
			lca[cur.first][0] = node;
			dist[cur.first][0] = cur.second;
			calcLCA(cur.first, node, d+1);
		}
	}
}

int getAns(int p, int q) {
	if(depth[p] < depth[q]) {
		swap(p, q);
	}
	int ans = 1e7;
	for(int i = 17; i >= 0; i--) {
		if(depth[p] - (1 << i) >= depth[q]) {
			ans = min(ans, dist[p][i]);
			p = lca[p][i];
		}
		if(p == q) {
			return ans;
		}
	}

	for(int i = 17; i >= 0; i--) {
		if(lca[p][i] != -1 && lca[p][i] != lca[q][i]) {
			ans = min(ans, dist[p][i]);
			ans = min(ans, dist[q][i]);
			p = lca[p][i];
			q = lca[q][i];
		}
	}
	return min(ans, min(dist[p][0], dist[q][0]));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, S; cin >> N >> M >> S;
	for(int i = 0; i < N; i++) {
		ds.push_back(i); dsrank.push_back(0);
	}
	vector<vector<int>> bridges;
	for(int i = 0; i < M; i++) {
		int a, b, w; cin >> a >> b >> w;
		a--; b--;
		bridges.push_back({w, b, a});
	}
	sort(bridges.rbegin(), bridges.rend());
	
	for(auto b : bridges) {
		if(find(b[1]) != find(b[2])) {
			merge(b[1], b[2]);
			adj[b[1]].push_back({b[2], b[0]});
			adj[b[2]].push_back({b[1], b[0]});
		}
	}

	memset(lca, -1, sizeof lca);
	calcLCA(0, -1, 0);

	for(int i = 0; i < S; i++) {
		int l, h; cin >> l >> h;
		l--; h--;
		cout << getAns(l, h) << endl;
	}
	
	return 0;
}