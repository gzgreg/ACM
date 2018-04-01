#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define N 1500*1500 + 10
#define M 1500*1500*2 + 10
#define endl '\n'

int vcompNum,ecompNum,I,m;
int first[N],low[N],vis[N],ecomp[N];
int nxt[2*M],ep[2*M],vcomp[2*M];
stack<int> edges, verts;
void init() { m = 0; memset(first, -1, sizeof(first)); }
void add_edge(int a, int b) {
    nxt[m] = first[ep[m] = a], first[ep[m]] = m, ++m;
    nxt[m] = first[ep[m] = b], first[ep[m]] = m; ++m; }
void biconnected(int u, int par){ int v,E; low[u] = vis[u] = ++I; verts.push(u);
  for (int e = first[u]; e != -1; e = nxt[e]) { v = ep[e^1];
    if (!vis[v]) { edges.push(e); biconnected(v,e); low[u] = min(low[u],low[v]);
      if (vis[u] <= low[v]) { // u is a cut vertex unless it's a one-child root
        do { E = edges.top(); edges.pop(); vcomp[E] = vcomp[E^1] = vcompNum; }
        while (e != E && e != (E^1)); ++vcompNum; }}
    else if (vis[v] < vis[u] && e != (par^1)) {
      low[u] = min(low[u], vis[v]); edges.push(e); }
    else if (v == u) vcomp[e] = vcomp[e^1] = vcompNum++; } // e is a self-loop
  if (vis[u] <= low[u]) { // par is a cut edge unless par==-1
    do { v = verts.top(); verts.pop(); ecomp[v] = ecompNum; }
    while (v != u); ++ecompNum; }
}
void get_bcc(int n) { memset(vis,0,sizeof vis); vcompNum=ecompNum=I=0;
  for (int i=0; i<n; ++i) if (!vis[i]) biconnected(i, -1);
}

int n, mm, q; 
vector<string> grid;

inline int getIndex(int i, int j) {
	return i*mm + j;
}

inline bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < mm && grid[i][j] != '#';
}

inline int _hash(int id, int dir) {
	return id*4 + dir;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("pushabox.in", "r", stdin);
	// freopen("pushabox.out", "w", stdout);
    auto t = clock();
	cin >> n >> mm >> q;

	pii start, end;
	for(int i = 0; i < n; i++) {
		string cur; cin >> cur; grid.push_back(cur);
	}
	init();
	map<ll, int> edgeToId;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < mm; j++) {
			if(grid[i][j] == '#') continue;

			vector<pii> nextPos = {{i-1, j}, {i, j-1}};
			ll id2 = getIndex(i, j);
			for(auto cur : nextPos) {
				if(!valid(cur.first, cur.second)) continue;
				ll id1 = getIndex(cur.first, cur.second);
				edgeToId[id1 * 1e7 + id2] = m;
				edgeToId[id2 * 1e7 + id1] = m;
				add_edge(id1, id2);
			}

			if(grid[i][j] == 'A') start = {i, j};
			if(grid[i][j] == 'B') end = {i, j};
		}
	}
	cout << (double) (clock() - t) / CLOCKS_PER_SEC << endl;

	get_bcc(n);
	vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	map<int, vector<int>> adj;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < mm; j++) {
			if(grid[i][j] == '#') continue;
			int idCenter = getIndex(i, j);
			for(int k = 0; k < 4; k++) {
				if(!valid(i+dir[k][0], j + dir[k][1])) {
					continue;
				}

				ll id1 = getIndex(i + dir[k][0], j + dir[k][1]);
				for(int l = k+1; l < 4; l++) {
					if(!valid(i+dir[l][0], j + dir[l][1])) {
						continue;
					}
					ll id2 = getIndex(i + dir[l][0], j + dir[l][1]);
					if(vcomp[edgeToId[id1*1e7 + idCenter]] == vcomp[edgeToId[id2*1e7 + idCenter]]) {
						adj[_hash(idCenter, k)].push_back(_hash(idCenter, l));
						adj[_hash(idCenter, l)].push_back(_hash(idCenter, k));
					}
				}
			}
		}
	}
	cout << (double) (clock() - t) / CLOCKS_PER_SEC << endl;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < mm; j++) {
			if(grid[i][j] == '#') continue;
			for(int k = 0; k < 4; k++) {
				pii nextLoc = {i - dir[k][0], j - dir[k][1]};
				if(!valid(nextLoc.first, nextLoc.second)) continue;
				int id1 = getIndex(i, j);
				int id2 = getIndex(nextLoc.first, nextLoc.second);
				adj[_hash(id1, k)].push_back(_hash(id2, k));
			}
		}
	}
	cout << (double) (clock() - t) / CLOCKS_PER_SEC << endl;

	queue<pii> bfsq;
	vector<vector<int>> vis(n, vector<int>(mm, false));

	bfsq.push(start);
	int startState;
	bool found = false;
	while(!bfsq.empty()) {
		auto cur = bfsq.front(); bfsq.pop();
		if(vis[cur.first][cur.second]) continue;
		vis[cur.first][cur.second] = true;

		for(int i = 0; i < 4; i++) {
			pii nextLoc = cur;
			nextLoc.first -= dir[i][0];
			nextLoc.second -= dir[i][1];
			if(!valid(nextLoc.first, nextLoc.second)) continue;
			if(nextLoc == end) {
				startState = _hash(getIndex(nextLoc.first, nextLoc.second), i);
				found = true;
				break;
			}
			bfsq.push(nextLoc);
		}
		if(found) break;
	}

	if(!found) {	
		cout << (double) (clock() - t) / CLOCKS_PER_SEC << endl;

		for(int i = 0; i < q; i++) {
			int x, y; cin >> x >> y; x--; y--;
			if(pii(x, y) == end) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
		return 0;
	} 

	queue<int> bfsq2;
	unordered_set<int> vis2;
	bfsq2.push(startState);
	while(!bfsq2.empty()) {
		auto cur = bfsq2.front(); bfsq2.pop();
		if(vis2.count(cur)) continue;
		vis2.insert(cur);
		for(auto next : adj[cur]) {
			bfsq2.push(next);
		}
	}
	cout << (double) (clock() - t) / CLOCKS_PER_SEC << endl;

	for(int i = 0; i < q; i++) {
		int x, y; cin >> x >> y; x--; y--;
		bool found = false;
		for(int j = 0; j < 4; j++) {
			if(vis2.count(_hash(getIndex(x, y), j))) {
				found = true;
				break;
			}
		}
		if(found) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	
	return 0;
}