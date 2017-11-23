#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define N 1000000

vector<ll> nodeWeights;
map<pii, pair<ll, ll>> weights;
vector<unordered_map<int, ll>> newWeights;

vector<vector<ll>> newAdj;
vector<ll> tot;

ll low[N],vis[N],scomp[N],scompNum,I;
vector<ll> adj[N]; stack<ll> verts;
void scc(ll u) { low[u] = vis[u] = ++I; verts.push(u);
  for (ll v : adj[u]) {
    if (!vis[v]) scc(v);
    if (scomp[v] == -1) low[u] = min(low[u], low[v]); }
  if (vis[u] <= low[u]) { ll v;
    do { v=verts.top(); verts.pop(); scomp[v]=scompNum; } while (v != u);
    ++scompNum; }}
void get_scc(ll n) { memset(vis,0,sizeof vis); memset(scomp,-1,sizeof scomp);
  scompNum=I=0; for (ll i=0; i<n; ++i) if (!vis[i]) scc(i); }

ll dfs(ll node) {
	ll ans = 0;
	if(tot[node] != -1) return tot[node];
	for(auto cur : newAdj[node]) {
		ans = max(ans, dfs(cur) + newWeights[node][cur]);
	}
	ans += nodeWeights[node];
	tot[node] = ans;
	return ans;
}

inline char get(void) {
	static char buf[100000], *S = buf, *T = buf;
	if (S == T) {
		T = (S = buf) + fread(buf, 1, 100000, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}
inline void read(ll &x) {
	static char c; x = 0; int sgn = 0;
	for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
	for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
	if (sgn) x = -x;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, m; read(n); read(m);
	for(ll i = 0; i < m; i++) {
		ll x, y, w; read(x); read(y); read(w);
		ll w2 = w;
		x--; y--;
		ll l = 0;
		for(ll i = 1LL << 15; i > 0; i >>= 1) {
			if((l+i)*(l+i+1) / 2 < w) {
				l += i;
			}
		}
		w2 = (l+1)*w - l*(l+1)*(l+2) / 6;
		auto curWeight = weights[{x, y}];
		curWeight.first = max(curWeight.first, w);
		curWeight.second += w2;
		weights[{x, y}] = curWeight;
		adj[x].push_back(y);
	}
	ll s; read(s);

	for(auto cur : weights) {
		weights[cur.first] = cur.second;
	}

	get_scc(n);
	nodeWeights = vector<ll>(scompNum, 0);
	newAdj = vector<vector<ll>>(scompNum);
	tot = vector<ll>(scompNum, -1);
	newWeights = vector<unordered_map<int, ll>>(scompNum);
	for(auto cur : weights) {
		if(scomp[cur.first.first] == scomp[cur.first.second]) {
			nodeWeights[scomp[cur.first.first]] += cur.second.second;
		} else {
			pii newEdge = {scomp[cur.first.first], scomp[cur.first.second]};
			newWeights[newEdge.first][newEdge.second] 
				= max(newWeights[newEdge.first][newEdge.second], cur.second.first);
			newAdj[newEdge.first].push_back(newEdge.second);
		}
	}
	cout << dfs(scomp[s-1]) << endl;

	return 0;
}