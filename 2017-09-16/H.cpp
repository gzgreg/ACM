#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	ll best = 0;
	for(int i = 0; i < n; i++) {
		ll cur; cin >> cur; best = max(cur, best);
	}

	for(ll i = 0; i < 40; i++) {
		if((1 << i) - 1 == best) {
			cout << "Mike" << endl;
			return 0;
		}
	}
	cout << "Constantine" << endl;
	
	return 0;
}