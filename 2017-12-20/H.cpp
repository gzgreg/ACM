#include <bits/stdc++.h>

using namespace std;
typedef long double ll;
typedef long long lli;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll is_query = -(1LL<<62);
struct Line {
  ll m, b; int i;
  mutable function<const Line*()> succ;
  bool operator<(const Line& rhs) const {
    if (rhs.b != is_query) return m < rhs.m;
    const Line* s = succ();
    if (!s) return 0;
    ll x = rhs.m;
    return b - s->b < (s->m - m) * x;
  }
};
int curId;
// will maintain upper hull for maximum
struct HullDynamic : public multiset<Line> {
  bool bad(iterator y) {
    auto z = next(y);
    if (y == begin()) {
      if (z == end()) return 0;
      return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()) return y->m == x->m && y->b <= x->b;
    // could overflow
    return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m);
  }
  void insert_line(ll m, ll b, int i) { // m = -m; b = -b; // for lower hull
    auto y = insert({ m, b, i});
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) { erase(y); return; }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }
  ll eval(ll x) {
    auto l = *lower_bound((Line) { x, is_query, -1});
    curId = l.i;
    return l.m * x + l.b; // return -(l.m * x + l.b); // for lower hull
  }
};

vector<int> p;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, F; cin >> N >> M >> F;

	for(int i = 0; i < N; i++) {
		int pi; cin >> pi; p.push_back(pi); 
	}
	p.push_back(0);

	HullDynamic hull;
	vector<ll> dp(N+1);
	vector<ll> parent(N+1, -1);
	dp[0] = M;
	for(int i = 0; i < N; i++) {
		hull.insert_line((lli) max(dp[i] - F + 0.5, 0.0L) / (lli) p[i], -F + ((lli) max(dp[i] + 0.5 - F, 0.0L)) % ((lli) p[i]), i);
		ll value = hull.eval(p[i+1]);
		if(value > dp[i]) {
			dp[i+1] = value;
			parent[i+1] = curId;
		} else {
			dp[i+1] = dp[i];
		}
	}
	vector<lli> ans (N);

	int curVal = N-1;
	while(curVal > 0) {		if(parent[curVal] == -1) {
			ans[curVal] = 0;
			curVal--;
		} else {
			ans[curVal] = -(lli) (dp[parent[curVal]] - F + 0.5) / (lli) p[parent[curVal]];
			for(int i = curVal - 1; i > parent[curVal]; i--) {
				ans[i] = 0;
			}
			ans[parent[curVal]] = (lli) (dp[parent[curVal]] - F + 0.5) / (lli) p[parent[curVal]];
			curVal = parent[curVal] - 1;
		}
	}

	cout << (lli) dp[N] << endl;
	for(auto cur : ans) {
		cout << cur << endl;
	}

	return 0;
}