#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000000007

ll n, m;
vector<vector<ll>> adj;
vector<ll> par;
vector<ll> nxt;
ll k, x;

ll memo[100001][11][3];

ll dp(int node, int high, int parV) {
	if(memo[node][high][parV] != -1) {
		return memo[node][high][parV];
	}
	if(adj[node].size() == 1 && node != 0) {
		if(nxt[node] == -1) {
			if(high > 1 || (parV != 0 && high > 0)) {
				return 0;
			}
			if(parV == 1) {
				return k-1;
			}
			if(high == 0) {
				return m-1;
			}
			if(high == 1) {
				return 1;
			}
		} else {
			ll ans = 0;
			if(parV == 1) {
				ans += dp(nxt[node], high, parV) * (k-1);
				ans %= MOD;
			} else {
				ans += dp(nxt[node], high, parV) * (m-1);
				ans %= MOD;

				if(high > 0 && parV == 0) {
					ans += dp(nxt[node], high - 1, parV);
					ans %= MOD;
				}
			}
			return memo[node][high][parV] = ans;
		}
	}

	ll ans = 0;
	int prevNode = -1;
	for(int i = 0; i < adj[node].size(); i++) {
		if(adj[node][i] == par[node]) continue;
		if(prevNode != -1){
			if(nxt[prevNode] != -1) break;
			nxt[prevNode] = adj[node][i];
		} 
		prevNode = adj[node][i];
		par[adj[node][i]] = node;
	}
	int repChild = adj[node][0];
	if(adj[node][0] == par[node]) repChild = adj[node][1];
	if(nxt[node] != -1) {
		for(int i = 0; i <= high; i++) {
			ll tmp = dp(repChild, i, 0) * dp(nxt[node], high-i, parV);
			tmp %= MOD;
			tmp *= k-1;
			tmp %= MOD;
			ans += tmp;
			ans %= MOD;
			if(parV != 1) {
				tmp = dp(repChild, i, 2) * dp(nxt[node], high-i, parV);
				tmp %= MOD;
				tmp *= m-k;
				tmp %= MOD;
				ans += tmp;
				ans %= MOD;
			}
			if(parV == 0 && i < high) {
				ll tmp = dp(repChild, i, 1) * dp(nxt[node], high-i-1, parV);
				tmp %= MOD;
				ans += tmp;
				ans %= MOD;
			}
		}
	} else {
		ll tmp = dp(repChild, high, 0);
		tmp *= k-1;
		tmp %= MOD;
		ans += tmp;
		ans %= MOD;
		if(parV != 1) {
			tmp = dp(repChild, high, 2);
			tmp *= m-k;
			tmp %= MOD;
			ans += tmp;
			ans %= MOD;
		}
		if(parV == 0 && high > 0) {
			ll tmp = dp(repChild, high-1, 1);
			ans += tmp;
			ans %= MOD;
		}
	}
	return memo[node][high][parV] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	adj = vector<vector<ll>>(n, vector<ll>());
	par = vector<ll>(n, -1);
	nxt = vector<ll>(n, -1);

	for(int i = 0; i < n-1; i++) {
		int ui, vi; cin >> ui >> vi;
		ui--; vi--;
		adj[ui].push_back(vi);
		adj[vi].push_back(ui);
	}

	cin >> k >> x;

	memset(memo, -1, sizeof memo);
	ll ans = 0;
	for(int i = 0; i <= x; i++) {
		ans += dp(0, i, 0);
		ans %= MOD;
	}
	cout << ans << endl;
	
	return 0;
}