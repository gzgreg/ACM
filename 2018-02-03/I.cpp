#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 5000000
//tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> unused;
struct BITree { ll freq[MAXN+1]; BITree() { memset(freq, 0, sizeof freq); }
  void insert(int x, ll cnt=1) {
    for ( ; x <= MAXN; x += x & -x) freq[x] += cnt;
      //for (int y = argy; y <= MAXN; y += y & -y) freq[x][y] += cnt;
  }
  ll query(int x) { ll sum = 0;
    for ( ; x; x -= x & -x) sum += freq[x];
      //for (int y = argy; y; y -= y & -y) sum += freq[x][y];
    return sum; }
  void insert_range(int xl,int xr,ll cnt=1) {insert(xl,cnt); insert(xr+1,-cnt);}
  ll query_range(int xl, int xr) { return query(xr) - query(xl-1); }
  int get_nth(ll n) { int x = 1<<30; // assumes non-negative frequencies
    for (int step = x>>1; step; step >>= 1)
      if (x-step > MAXN || freq[x-step] >= n) x -= step; else n -= freq[x-step];
    return x; } };

BITree unused;
void build_tree(int sz) {
	// queue<pair<int, int>> intervals;
	// intervals.push({1, sz});
	// while(!intervals.empty()) {
	// 	auto cur = intervals.front();
	// 	intervals.pop();
	// 	int mid = (cur.first + cur.second) / 2;
	// 	unused.insert(mid);
	// 	if(cur.first <= mid-1) intervals.push({cur.first, mid - 1});
	// 	if(mid+1 <= cur.second) intervals.push({mid+1, cur.second});
	// }
	for(int i = 0; i < sz; i++) {
		unused.insert(i+1);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	vector<int> B;
	for(int i = 0; i < N; i++) {
		int cur; cin >> cur; B.push_back(cur);
	}
	vector<int> ans(N);
	build_tree(N);
	int maxVal = N;
	for(int i = N-1; i >= 0; i--) {
		auto it = unused.get_nth(i - B[i]+1);
		ans[i] = it;
		unused.insert(it, -1);
	}
	for(auto cur : ans) {
		cout << cur << " ";
	}
	cout << endl;
	
	return 0;
}