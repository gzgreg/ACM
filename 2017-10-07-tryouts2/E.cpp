#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define N 1010

const ll INF = 1000000000000000LL;

//*/
//! w[i][j] = weight of edge from i on left side to j on right side
//! ml[i]   = matching of left vertex i
//! mr[i]   = matching of right vertex j
//! lbl[i]  = score of left vertex i
//! lbr[j]  = score of right vertex j
ll w[N][N], ml[N], mr[N], lbl[N], lbr[N], s[N], slack[N], par[N]; // Yury's
//! Run time is O(m * n^2)
ll wmatch(ll n, ll m){ // assume n <= m;
  ll i, j, k, done, al, nxt, out = 0;
  for(i=0;i<n;i++)for(j=0,lbl[i]=0,ml[i]=-1;j<m;j++) lbl[i]=max(lbl[i],w[i][j]);
  for(i = 0; i < m; i++) lbr[i] = 0, mr[i] = -1;
  for(i=0;i<n;i++) for(j = 0; j < m; j++) if(w[i][j] == lbl[i] && mr[j] == -1)
	{ ml[i] = j, mr[j] = i; break; }
  for(i = 0; i < n; i++) if(ml[i] == -1){
	for(j=0;j<m;j++) s[j]=(j==i), slack[j]=(lbl[i]+lbr[j]-w[i][j]), par[j] = -1;
	for(done = 0; !done;){
	  for(j = 0, al = INF; j < m; j++) if(par[j] == -1) al = min(al, slack[j]);
	  for(j = 0, lbl[j] -= s[j]*al; j < m; ++j, lbl[j] -= s[j]*al)
		if(par[j] != -1) lbr[j] += al; else slack[j] -= al;
	  for(j = 0; j < m; j++) if(!slack[j] && par[j] == -1){
		for(k=0;k<n;k++) if(s[k]&&(lbl[k]+lbr[j]==w[k][j])){ par[j] = k; break;}
		if(mr[j] == -1){ done = 1;
		  do{ nxt=ml[par[j]], mr[j]=par[j], ml[par[j]]=j, j=nxt;}while(j != -1);
		}else for(k = 0, s[mr[j]] = 1; k < m; k++)
		  slack[k] = min(slack[k], lbl[mr[j]] + lbr[k] - w[mr[j]][k]); break;}}}

  for(i = 0; i < n; i++) out += w[i][ml[i]]; return out; }


vector<vector<ll>> child(1000, vector<ll>());

void dfs(ll node, ll depth, set<ll>& l, set<ll>& r) {
	if(depth % 2) {
		l.insert(node);
	} else {
		r.insert(node);
	}

	for(auto i : child[node]) {
		dfs(i, depth + 1, l, r);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n; cin >> n;

	map<string, ll> idxMap;
	map<string, string> sup;
	vector<ll> par(n, -1);
	vector<ll> spd(n, -1);

	ll idx = 0;

	for(ll i = 0; i < n; i++) {
		string s; cin >> s;
		double curspd; cin >> curspd;
		curspd += 1e-7;
		string p; cin >> p;
		spd[i] = curspd * 1000;
		sup[s] = p;
		idxMap[s] = idx;
		idx++;
	}

	for(auto cur : sup) {
		if(cur.second != "CEO") {
			par[idxMap[cur.first]] = idxMap[cur.second];
			child[idxMap[cur.second]].push_back(idxMap[cur.first]);
		}
	}

	set<ll> left, right;
	dfs(0, 0, left, right);

	if(left.size() > right.size()) {
		swap(left, right);
	}

	map<ll, ll> idxMapL, idxMapR;
	idx = 0;
	for(ll i : left) {
		idxMapL[i] = idx;
		idx++;
		cout << i << endl;
	}
	idx = 0;
	for(ll i : right) {
		idxMapR[i] = idx;
		idx++;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			w[i][j] = 0;
		}
	}
	set<pii> tmp;
	for(ll i = 0; i < n; i++) {
		if(par[i] == -1) continue;
		ll l, r;
		if(left.count(i)) {
			l = idxMapL[i];
			r = idxMapR[par[i]];
		} else {
			l = idxMapL[par[i]];
			r = idxMapR[i];
		}
		tmp.insert({l, r});
		w[l][r] = 70000000 + min(spd[i], spd[par[i]]);
	}

	ll totSpd = wmatch(left.size(), right.size());
	ll numPairs = 0;
	for(int i = 0; i < left.size(); i++) {
		if(ml[i] != -1) {
			//if(!tmp.count({i, ml[i]})) {
				cout << i << " " << ml[i] << " " << w[i][ml[i]] << endl;
			//}
			if(w[i][ml[i]] != 0) {
				numPairs++;
				totSpd -= 70000000;
				cout << w[i][ml[i]] << endl;
			}
		}
	}
	cout << *++(++(++(left.begin()))) << " " << *right.begin() << endl;

	cout << numPairs << " " << fixed << setprecision(10);
	cout << (double) totSpd / numPairs / 1000 << endl;
	
	return 0;
}