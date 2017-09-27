#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define N 2002

const ll INF = 0x3f3f3f3f; const ld EPS = 1e-9; const ld PI = acos(-1.L);

typedef complex<ld> pt;

ld cp(const pt& a, const pt& b) { return imag(conj(a)*b); }
ld dp(const pt& a, const pt& b) { return real(conj(a)*b); }
inline ld sgn(const ld& x) { return abs(x) < EPS ? 0 : x/abs(x); }
inline bool cmp_lex(const pt& a, const pt& b) {
  return a.real() < b.real() || (a.real() == b.real() && a.imag() < b.imag()); }
inline bool cmp_lex_i(const pt& a, const pt& b) {
  return a.imag() < b.imag() || (a.imag() == b.imag() && a.real() < b.real()); }
bool seg_x_seg(pt a1, pt a2, pt b1, pt b2) {
  //if (a1==a2 || b1==b2) return false; // uncomment to exclude endpoints
  int s1 = sgn(cp(a2 - a1, b1 - a1)), s2 = sgn(cp(a2 - a1, b2 - a1));
  int s3 = sgn(cp(b2 - b1, a1 - b1)), s4 = sgn(cp(b2 - b1, a2 - b1));
  if(!s1 && !s2 && !s3) { // collinear
    if (cmp_lex(a2, a1)) swap(a1, a2); if (cmp_lex(b2, b1)) swap(b1, b2);
    //return cmp_lex(a1, b2) && cmp_lex(b1, a2);//uncomment to exclude endpoints
    return !cmp_lex(b2, a1) && !cmp_lex(a2, b1);
  } return s1*s2 <= 0 && s3*s4 <= 0; }

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
// usage:   for (int i = 0; i < 2*num_vars; ++i) adj[i].clear();
//          add_clause(2*x, 2*y^1); // example for x || !y
//          if (two_sat(2*num_vars)) // truth[] contains a satisfying assignment
//          else // no satisfying assignment exists
//*!

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 2000; ++i) adj[i].clear();

	int w, p; cin >> w >> p;

	vector<pt> wells;
	for(int i = 0; i < w; i++) {
		int xi, yi; cin >> xi >> yi; wells.emplace_back(xi, yi);
	}

	vector<pair<pt, pt>> pipes;
	vector<int> wellPipes (p);
	for(int i = 0; i < p; i++) {
		int s, xi, yi; cin >> s >> xi >> yi;
		s--;
		pipes.push_back({wells[s], {xi, yi}});
		wellPipes[i] = s;
	}

	for(int i = 0; i < p; i++) {
		for(int j = i+1; j < p; j++) {
			if(wellPipes[i] == wellPipes[j]) continue;
			if(seg_x_seg(pipes[i].first, pipes[i].second, pipes[j].first, pipes[j].second)) {
				add_clause(2*i, 2*j);
				add_clause(2*i^1, 2*j^1);
			}
		}
	}

	if(two_sat(2*p)) {
		cout << "possible" << endl;
	} else {
		cout << "impossible" << endl;
	}

	
	return 0;
}