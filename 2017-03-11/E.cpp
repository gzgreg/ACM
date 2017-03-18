#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

typedef struct Request {
	ll t;
	ll k;
	bool plus;
	Request(ll t, ll k, bool plus) : t(t), k(k), plus(plus) {
	}
} Request;

int main(){
	ios::sync_with_stdio(0);
	freopen("expect.in", "r", stdin);
	freopen("expect.out", "w", stdout);

	ll n, q; cin >> n >> q;

	vector<Request> requests;

	ll totalNeeded = 0;

	for(ll i = 0; i < n; i++) {
		string curr; ll t, k; cin >> curr >> t >> k;
		if(curr == "-") {
			requests.push_back(Request(t, k, false));
			totalNeeded += k;
		} else {
			requests.push_back(Request(t, k, true));
			totalNeeded -= k;
		}
	}

	map<ll, ll> waits;
	ll totalPeople = min(0LL, -totalNeeded);
	for(ll i = 1; i < requests.size(); i++) {
		if(requests[i-1].plus) {
			totalPeople -= requests[i-1].k;
		} else {
			totalPeople += requests[i-1].k;
		}
		ll waitTime = requests[i].t - requests[i-1].t;
		if(totalPeople > 0) waits[totalPeople] += waitTime;
	}

	vector<pii> waitPeople;
	ll worstAns = 0;
	for(pii curr : waits) {
		waitPeople.push_back(curr);
		worstAns += curr.first*curr.second;
		// cout << curr.first << " ";
	}
	// cout << endl;

	vector<ll> cumsum;
	cumsum.push_back(0);
	vector<ll> totsum;
	totsum.push_back(0);
	for(ll i = 0; i < waitPeople.size(); i++) {
		cumsum.push_back(cumsum[i] + waitPeople[i].first*waitPeople[i].second);
		totsum.push_back(totsum[i] + waitPeople[i].second);
	}
	// for(ll i : cumsum) {
	// 	cout << i << " ";
	// }
	// cout << endl;
	// for(ll i : totsum) {
	// 	cout << i << " ";
	// }
	// cout << endl;
	// cout << worstAns << endl;
	for(ll i = 0; i < q; i++) {
		ll curr; cin >> curr;
		if(curr < totalNeeded) {
			cout << "INFINITY" << endl;
			continue;
		}
		if(waitPeople.size() == 0) {
			cout << 0 << endl;
			continue;
		}
		curr -= max(0LL, totalNeeded);

		ll l = 0, r = waitPeople.size() - 1;
		while(l < r) {
			ll mid = l + (r-l) / 2;
			// cout << mid << " " << waitPeople[mid].first<< "|";
			if(waitPeople[mid].first < curr) {
				l = mid + 1;
			} else if (waitPeople[mid].first > curr) {
				r = mid - 1;
			} else {
				l = mid;
				r = mid;
				break;
			}
		}
		// cout << curr << " ";
		ll ans = worstAns;
		ans -= cumsum[l];
		ans -= (totsum[cumsum.size() - 1] - totsum[l]) * curr;
		if(ans < 0) ans = 0;
		cout << ans << endl;
	}

	return 0;
}