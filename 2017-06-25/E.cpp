#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define MOD 1000000007

vector<vector<ll>> buildMat(ll sz) {
	vector<vector<ll>> output(sz, vector<ll>(sz));

	for(ll i = 0; i < sz; i++) {
		for(ll j = 0; j < sz; j++) {
			if(i-j <= 1 && i-j >= -1) {
				output[i][j] = 1;
			} else {
				output[i][j] = 0;
			}
		}
	}
	return output;
}

vector<vector<ll>> matMultiply(vector<vector<ll>> a, 
	vector<vector<ll>> b) {
	vector<vector<ll>> output(a.size(), vector<ll>(b[0].size(), 0));

	for(ll i = 0; i < a.size(); i++) {
		for(ll j = 0; j < b[0].size(); j++) {
			for(ll k = 0; k < a[0].size(); k++) {
				ll nxt = a[i][k] * b[k][j];
				nxt %= MOD;
				output[i][j] += nxt;
				output[i][j] %= MOD;
			}
		}
	}
	return output;
}

vector<vector<ll>> mod(vector<vector<ll>> a) {
	for(ll i = 0; i < a.size(); i++) {
		for(ll j = 0; j < a[0].size(); j++) {
			a[i][j] %= MOD;
		}
	}

	return a;
}

vector<vector<ll>> mod_pow(vector<vector<ll>> base, ll exp) {
	vector<vector<ll>> val (base.size(), vector<ll>(base.size(), 0));
	for(ll i = 0; i < base.size(); i++) {
		val[i][i] = 1;
	}
	base = mod(base);
	while(exp > 0) {
		if(exp % 2 == 1) {
			val = matMultiply(val, base);
			val = mod(val);
		}
		exp = exp / 2;
		base = matMultiply(base, base);
		base = mod(base);
	}

	return val;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	ll n, k; cin >> n >> k;

	vector<pair<pii, ll>> segs;
	for(ll i = 0; i < n; i++) {
		ll ai, bi, ci; cin >> ai >> bi >> ci;
		segs.push_back({{ai, bi}, ci});
	}
	vector<vector<ll>> startVec (16, vector<ll>(1, 0));
	startVec[0][0] = 1;
	for(ll i = 0; i < n; i++) {
		ll ai = segs[i].first.first, bi = min(segs[i].first.second, k);
		ll ci = segs[i].second;
		vector<vector<ll>> newStartVec (ci + 1, vector<ll>(1, 0));
		for(ll i = 0; i < newStartVec.size(); i++) {
			if(i < startVec.size()) {
				newStartVec[i][0] = startVec[i][0];
			} else {
				newStartVec[i][0] = 0;
			}
		}
		startVec = newStartVec;

		vector<vector<ll>> mat = buildMat(ci + 1);
		mat = mod_pow(mat, bi - ai);
		startVec = matMultiply(mat, startVec);

		if(bi >= k) break;
	}
	cout << startVec[0][0] << endl;
	
	return 0;
}