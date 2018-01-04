#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct rational_t { ll nu, de;
  rational_t(const ll &n = 0, const ll &d = 1) {
    ll g = __gcd(abs(n), abs(d)); nu = n / g; de = d / g;
    if (de < 0) { nu = -nu; de = -de; } }
  rational_t operator+(const rational_t& b) const
  { return rational_t( nu*b.de+de*b.nu, de*b.de ); }
  rational_t operator-(const rational_t& b) const
  { return rational_t( nu*b.de-de*b.nu, de*b.de ); }
  rational_t operator-() { return rational_t(-nu, de); }
  rational_t operator*(const rational_t& b) const
  { return rational_t( nu*b.nu, de*b.de ); }
  rational_t operator/(const rational_t& b) const
  { return rational_t( nu*b.de, de*b.nu ); }
  bool operator== (const rational_t & b) const {return nu * b.de == b.nu * de;}
  bool operator== (const int &k) const { return nu == k * de; }
  bool operator< (const rational_t& b) const { return nu * b.de < b.nu * de; }};

int numAs = 0;
ld ans;
ld totProb;
ld prob;
int k, pa, pb;
void dfs(int depth, ld curProb, int curVal) {
	if(curProb < 1e-10 || depth > 1000) return;
	numAs++;
	dfs(depth+1, curProb * prob, curVal);
	numAs--;
	curVal += numAs;
	if(curVal >= k) {
		ans = ans + curProb * curVal;
		totProb = totProb + curProb;
		return;
	}
	dfs(depth+1, curProb * (1-prob), curVal);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> k >> pa >> pb;

	prob = (ld) pa / (pb + pa);

	dfs(0, 1, 0);
	ans = ans / totProb;
	cout << fixed << setprecision(15) << ans << endl;
	cout << totProb << endl;

	return 0;
}