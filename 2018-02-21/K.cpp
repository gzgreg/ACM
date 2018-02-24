#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define N 401

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

////////////////////////////////////////////////////////////////////////////////
// 2-SAT using SCC (previous version was TESTED F - SouthAmerica03)
////////////////////////////////////////////////////////////////////////////////
bool truth[N/2]; // N must be at least 2 times the number of variables
// the clause a || b becomes !a => b and !b => a in the implication graph
void add_clause(int a, int b) { adj[a^1].push_back(b); adj[b^1].push_back(a); }
bool two_sat(int n) { get_scc(n);
  for (int i = 0; i < n; i += 2) { if (scomp[i] == scomp[i^1]) return false;
    truth[i/2] = (scomp[i] < scomp[i^1]); } return true; }

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<int> type;
	vector<vector<int>> pref(n);
	vector<pii> classes = {{1, 2}, {0, 2}, {0, 1}};
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; type.push_back(cur);
		for(int j = 0; j < n-1; j++) {
			int val; cin >> val; val--; pref[i].push_back(val);
		}
	}

	for(int i = 0; i <= n-1; i++) {
		int curVal = i;

		for(int i = 0; i < 2*n; ++i) adj[i].clear();

		for(int j = 0; j < n; j++) {
			for(int k = curVal; k < n-1; k++) {
				int other = pref[j][k];
				if(classes[type[j]].first == classes[type[other]].first) {
					add_clause(2*j, 2*other);
				}
				if(classes[type[j]].first == classes[type[other]].second) {
					add_clause(2*j, 2*other^1);
				}
				if(classes[type[j]].second == classes[type[other]].first) {
					add_clause(2*j^1, 2*other);
				}
				if(classes[type[j]].second == classes[type[other]].second) {
					add_clause(2*j^1, 2*other^1);
				}
			}
		}
		if(two_sat(2*n)) {
			cout << curVal << endl;
			return 0;
		}
	}
	return 0;
}