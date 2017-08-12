#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define MOD 1000000007

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<ll> fac (1000001);

	for(ll i = 2; i < 1000001; i++) {
		fac[i] += i;
		ll curr = 2*i;
		while(curr < 1000001) {
			fac[curr] -= fac[i];
			curr += i;
		}
	}

	vector<ll> cnt (1000001);

	ll n; cin >> n;
	for(ll i = 0; i < n; i++) {
		ll cur; cin >> cur;
		for(ll j = 2; j < sqrt(cur) + 1; j++) {
			if(cur % j == 0 && j <= cur / j) {
				cnt[j]++;
				if(j != cur / j) {
					cnt[cur / j]++;
				}
			}
		}
		cnt[cur]++;
	}

	vector<ll> prod(200001);
	ll ans = 0;
	ll power = 1;
	for(ll i = 1; i < 200001; i++) {
		prod[i] = power * i;
		prod[i] %= MOD;
		power *= 2;
		power %= MOD;
	}

	for(ll i = 2; i < 1000001; i++) {
		ans += prod[cnt[i]] * fac[i];
		ans %= MOD;
	}

	cout << ans << endl;

	return 0;
}