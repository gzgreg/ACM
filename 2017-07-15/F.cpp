#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll z[1000006];
void build_zval(const string& s) { memset(z, 0, sizeof z);
  ll L = 0, R = 0; ll n = s.size(); z[0] = n;
  for (ll i = 1; i < n; i++) {
    if (i > R) { L = R = i;
      while (R < n && s[R-L] == s[R]) R++;
      z[i] = R-L; R--;
    } else if (z[i-L] < R-i+1) { z[i] = z[i-L];
    } else { L = i; while (R < n && s[R-i] == s[R]) R++; z[i] = R-L; R--; } } }

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	
	string s; cin >> s;

	if(s.size() <= 2) {
		cout << 0 << endl;
		return 0;
	}
	build_zval(s);
	priority_queue<pair<ll, ll>> pq;
	ll end1 = 0, end2 = 0;
	for(ll i = 1; i < s.size(); i++) {
		if(z[i] == 0) continue;
		if(z[i]+i > end1) {
			end2 = end1;
			end1 = z[i] + i;
			pq.push({z[i], i});
		} else if (z[i] + i > end2) {
			end2 = z[i] + i;
			pq.push({z[i], i});
		}
	}
	vector<ll> ans (s.size(), 0);
	set<ll> vals;
	ll start = pq.top().first;
	for(ll i = start; i > 0; i--) {
		while(!pq.empty() && pq.top().first >= i) {
			vals.insert(pq.top().second); pq.pop();
		}
		for(auto it = vals.begin(); it != vals.end(); it++) {
			if(it == vals.begin()) continue;
			ans[*it + i - 1] = max(ans[*it + i - 1], i);
		}
	}

	ll tot = 0;
	for(ll i : ans) {
		tot += i;
	}
	cout << tot << endl;

	return 0;
}