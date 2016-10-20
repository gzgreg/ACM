#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'
#define N 100001

int low[N],vis[N],scomp[N],scompNum,I;
vector<int> adj[N]; stack<int> verts;
void scc(int u) { low[u] = vis[u] = ++I; verts.push(u);
  for (int v : adj[u]) {
    if (!vis[v]) scc(v);
    if (scomp[v] == -1) low[u] = min(low[u], low[v]); }
  if (vis[u] <= low[u]) { int v;
    do { v=verts.top(); verts.pop(); scomp[v]=scompNum; } while (v != u);
    ++scompNum; }}
void get_scc(int n) { memset(vis,0,sizeof vis); memset(scomp,-1,sizeof scomp);
  scompNum=I=0; for (int i=0; i<n; ++i) if (!vis[i]) scc(i); }

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < N; ++i) {
	      	adj[i] = vector<int>();
	    }
		for(int i = 0; i < m; i++) {
			int x, y; cin >> x >> y;
			adj[x-1].push_back(y-1);
		}
		
		get_scc(n);
		set<int> nums;
		for(int i = 0; i < scompNum; i++) {
			nums.insert(i);
		}

		for(int i = 0; i < n; i++) {
			for(int j : adj[i]) {
				if(scomp[i] != scomp[j]) nums.erase(scomp[j]);
			}
		}

		cout << nums.size() << endl;
	}
	
	return 0;
}