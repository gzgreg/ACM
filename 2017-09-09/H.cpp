#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define N 2552
#define M 2500 + 50 + 2500*50

struct bear {
	int b;
	int x;
	int y;
	int r;
};

const ll INF = 0x3f3f3f3f;

int par[N], first[N], nxt[2*M], ep[2*M], m;
ll flo[2*M], cap[2*M], cost[2*M];
void init() { m = 0; memset(first,-1,sizeof first); memset(flo,0,sizeof flo); }
void add_edge(int a, int b, ll c=1, ll p=0) { //a,b - nodes, c, p - cap, price
  nxt[m] = first[ep[m]=a], first[ep[m]] = m, cap[m] = c, cost[m] =  p, ++m;
  nxt[m] = first[ep[m]=b], first[ep[m]] = m, cap[m] = 0, cost[m] = -p, ++m; }
 
// Dinic's fast maximum flow: tested on NAIPC 2015 F but not theoretically
// proven to be floating-point-safe.
// USAGE: 1) init(); 2) add edges
// 3) ll flow=0; while (bfs(S, T)) flow += dfs(S, T, INF);
// V^2E in general, min(V^(2/3),sqrt(E))E on unit caps, sqrt(V)E on bipartite
int L[N], cur[N];
bool bfs(int s, int t) {
  memset(L, INF, sizeof L);
  queue<int> q; q.push(s); L[s] = 0;
  while (!q.empty()) { int u = q.front(); q.pop();
    for (int v, e = cur[u] = first[u]; e != -1; e = nxt[e])
      if (L[v=ep[e^1]] == INF && flo[e] < cap[e])
        q.push(v), L[v] = L[u]+1;
  } return L[t] < INF; }
ll dfs(int u, int t, ll f) {
  if (u == t) return f;
  ll cf, df = 0;
  for (int v, e = cur[u]; e != -1 && df < f; cur[u] = e = nxt[e])
    if (flo[e] < cap[e] && L[v=ep[e^1]] == L[u]+1) {
      cf = dfs(v, t, min(cap[e]-flo[e], f-df));
      flo[e] += cf; flo[e^1] -= cf; df += cf;
    } return df; }

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;

	vector<pii> berries;
	for(int i = 0; i < n; i++) {
		int x, y; cin >> x >> y; berries.push_back({x, y});
	}

	vector<bear> bears;
	int totBerries = 0;
	for(int i = 0; i < m; i++) {
		int xi, yi, ri, bi; cin >> xi >> yi >> ri >> bi;
		bears.push_back({bi, xi, yi, ri});
		totBerries += bi;
	}

	ll bestAns = -1;
	for(int excl = 0; excl < m; excl++) {
		init();
		for(int i = 2; i < n+2; i++) {
			add_edge(0, i, 1);
		}

		for(int i = n+2; i < n + m + 2; i++) {
			add_edge(i, 1, bears[i-n-2].b);
		}

		for(int i = 0; i < m; i++) {
			if(i == excl) continue;
			for(int j = 0; j < n; j++) {
				if((bears[i].x - berries[j].first)*(bears[i].x - berries[j].first)
					+ (bears[i].y - berries[j].second)*(bears[i].y - berries[j].second) < bears[i].r*bears[i].r) {
					add_edge(2+j, 2+n+i, 1);
				}
			}
		}
		ll flow=0; while (bfs(0, 1)) flow += dfs(0, 1, INF);
		if(flow == totBerries - bears[excl].b) {
			bestAns = max(bestAns, n - flow);
		}
	}

	cout << bestAns << endl;
	
	return 0;
}