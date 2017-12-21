#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

//*/
// WARNING: could overflow for values ~1e9, use __int128 instead
// WARNING: tested only with integer and rational types
typedef long double ll;
const ll is_query = -(1LL<<62);
struct Line {
  ll m, b;
  mutable function<const Line*()> succ;
  bool operator<(const Line& rhs) const {
    if (rhs.b != is_query) return m < rhs.m;
    const Line* s = succ();
    if (!s) return 0;
    ll x = rhs.m;
    return b - s->b < (s->m - m) * x;
  }
};
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
  void insert_line(ll m, ll b) { // m = -m; b = -b; // for lower hull
    auto y = insert({ m, b });
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) { erase(y); return; }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }
  ll eval(ll x) {
    auto l = *lower_bound((Line) { x, is_query });
    return l.m * x + l.b; // return -(l.m * x + l.b); // for lower hull
  }
};

vector<int> cumsum;

vector<HullDynamic> hulls;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	int tot = 0;
	cumsum.push_back(0);
	for(int i = 0; i < N; i++) {
		int cur; cin >> cur; tot += cur;
		cumsum.push_back(tot);
	}

	ld best = 0;
	for(int i = 0; i < N; i++) {
		HullDynamic hull;
		hulls.push_back(hull);
		if(i != 0) {
			for(int j = 0; j < i; j++) {
				ld s = cumsum[i+1] - cumsum[j+1];
				hulls[i].insert_line(s, hulls[j].eval(s));
				if(i == N-1) best = max(best, hulls[j].eval(s));
			}
		}
		hulls[i].insert_line(cumsum[i+1], 0);
	}

	cout << fixed << setprecision(0) << best << endl;
	
	return 0;
}