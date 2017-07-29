#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct LinkCutTree { vector<int> l,r,p,pp,val,sum,carry,size,flip; int null;
  void init(int n) {
    vector<int>* v[] = {&l, &r, &p, &pp, &size, &val, &sum, &carry, &flip};
    int ival[] = {null=n, null, null, null, 1, 0, 0, 0, 0};
    for (int i = 0; i < 9; i++) { v[i]->clear(); v[i]->resize(n+1, ival[i]); }
    size[null] = 0; }
  inline int access(int x) {
    if(r[splay(x)] != null) r[pp[r[x]] = x] = p[r[x]] = null;
    for(int w=x; update(w)>=0 && splay(w=pp[x]) != null; splay(r[p[x]=w]=x))
      if(r[w] != null) p[r[pp[r[w]]=w]] = null;
    return x; }
  void makeroot(int x) { access(x); flip[x] ^= 1; push(x); }
  int findroot(int x) {
    for(access(x); l[x] != null; x = l[x]) {}
    return access(x); }
  int pathAggregate(int x) { return sum[access(x)]; }
  int pathAggregate(int x, int y) { makeroot(x); return pathAggregate(y); }
  void cut(int x) { l[x] = p[l[access(x)]] = null; }
  void cut(int x, int y) { makeroot(y); cut(x); }
  void link(int x, int y) { makeroot(x); l[p[access(y)]=access(x)] = y; }
  void pathUpdate(int x, int y, int c) { int z = lca(x,y);
    if(x != z) carry[x] += c; if(y != z) carry[y] += c;
    val[z] += c; }
  inline int splay(int x) {
    for(push(x); p[x] != null; lift(x))
      if(l[l[p[p[x]]]] == x || r[r[p[p[x]]]] == x) lift(p[x]);
      else lift(x);
    return x; }
  void push(int x) {
    if(flip[x]==1) {
      swap(l[x], r[x]);
      flip[x]^=1; flip[l[x]]^=1; flip[r[x]]^=1; }
    val[x] += carry[x];
    carry[l[x]] += carry[x]; carry[r[x]] += carry[x];
    carry[x] = 0; }
  int update(int x) {
    if(x == null) return x;
    size[x] = size[l[x]] + size[r[x]] + 1;
    sum[x] = val[x]+sum[l[x]]+sum[r[x]] + carry[x]*size[x];
    return x; }
  int lca(int x, int y) {
    access(x); access(y); splay(x);
    return access(pp[x]==null?x:pp[x]); }
  void lift(int x) {
    if(p[x] == null) return;
    push(p[x]); push(x); push(l[x]); push(r[x]);
    pp[x] = pp[p[x]]; pp[p[x]] = null;
    int* a=&l[0], *b=&r[0];
    if(r[p[x]]==x) {a=&r[0]; b=&l[0];}
    a[p[x]] = b[x]; b[x] = p[x]; p[x] = p[p[x]];
    if(p[x] != null) {
      if(a[p[x]] == b[x]) a[p[x]] = x;
      else b[p[x]] = x; }
    if(a[b[x]] != null) p[a[b[x]]] = b[x];
    update(l[b[x]]); update(r[b[x]]);
    update(p[update(b[x])] = x); } };


	LinkCutTree tree;

int solve(vector<int> vals) {
	int s = vals[0], f = vals[1], t = vals[2];
	tree.pathUpdate(t, f, 1);
	//cout << s << " " << f << " " << t << " " << tree.pathAggregate(s, f) << endl;
	tree.pathAggregate(s, f);
	int ans = tree.pathAggregate(s, f);
	for(int i = 0; i < 5; i++) {
		tree.pathAggregate(i, 4);
	}
	tree.pathUpdate(t, f, -1);
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	int n, q; cin >> n >> q;
	tree.init(n+5);
	for(int i = 0; i < n-1; i++) {
		int a; cin >> a;
		tree.link(i+1, a-1);
	}

	for(int i = 0; i < q; i++) {
		int a, b, c; cin >> a >> b >> c;
		a--; b--; c--;		
		vector<int> vals = {a, b, c};
		sort(vals.begin(), vals.end());
		int curBest = 0;
		curBest = max(max(solve({a, b, c}), solve({a, c, b})), solve({b, a, c}));
		//cout << curBest << endl;
		curBest = max(max(curBest, solve({b, c, a})), max(solve({c, a, b}), solve({c, b, a})));
		// do {
		// 	curBest = max(curBest, solve(vals));
		// } while(next_permutation(vals.begin(), vals.end()));
		cout << curBest << endl;
	}
	
	return 0;
}