#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define N 200001

int low[N],vis[N],scomp[N],scompNum,I;
vector<int> adj[N]; stack<int> verts;
set<int> adj2[N];
int n, m; 
void scc(int u) { low[u] = vis[u] = ++I; verts.push(u);
  for (int v : adj[u]) {
    if (!vis[v]) scc(v);
    if (scomp[v] == -1) low[u] = min(low[u], low[v]); }
  if (vis[u] <= low[u]) { int v;
    do { v=verts.top(); verts.pop(); scomp[v]=scompNum; } while (v != u);
    ++scompNum; }}
void get_scc(int n) { memset(vis,0,sizeof vis); memset(scomp,-1,sizeof scomp);
  scompNum=I=0; for (int i=0; i<n; ++i) if (!vis[i]) scc(i); }

void generateSccAdj() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < adj[i].size(); j++) {
			if(scomp[i] == scomp[adj[i][j]]) continue;
			adj2[scomp[i]].insert(scomp[adj[i][j]]);
		}
	}
}

vector<double> label;
double memo[200001];
double dp(int node) {
	if(memo[node] > 1e-15) {
		return memo[node];
	}
	double ans = label[node];
	for(auto cur : adj2[node]) {
		ans = min(dp(cur), ans);
	}
	return memo[node] = ans;
}

double get_rand() { return (double)(rand()<<15|rand()) / (RAND_MAX<<15|RAND_MAX); }

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    auto t = clock();
	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
	}

	get_scc(n);
	generateSccAdj();
	vector<int> scompSize(scompNum);
	for(int i = 0; i < n; i++) {
		scompSize[scomp[i]]++;
	}
	const int MAX = n+1;
	std::mt19937 rng;
    rng.seed(0);
	uniform_real_distribution<> dis(0.0, 1.0);
	vector<double> ans (scompNum, 0);
	int ITERS = 0;

	while(ITERS < 40) {
		label = vector<double> (scompNum, 1.0);

		memset(memo, 0.0, sizeof memo);
		for(int i = 0; i < scompNum; i++) {
			for(int j = 0; j < scompSize[i]; j++) {
				label[i] = min(label[i], dis(rng));
			}
		}
		// for(auto cur : label) {
		// 	cout << cur << " ";
		// }
		// cout << endl;
		for(int i = 0; i < scompNum; i++) {
			ans[i] += dp(i);
			//cout << ans[i] << " ";
		}
		//cout << endl;
		ITERS++;
		if((double) (clock() - t) / CLOCKS_PER_SEC > 5.9) break;
	}
	for(int i = 0; i < scompNum; i++) {
		ans[i] /= ITERS;
		ans[i] = 1.0 / ans[i] - 1;
		if(ans[i] < 0.5) ans[i] = 1;
	}
	for(int i = 0; i < n; i++) {
		cout << (int) (ans[scomp[i]] + 0.5) << '\n';
	}

	return 0;
}