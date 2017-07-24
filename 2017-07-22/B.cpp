#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	ll n, a; cin >> n >> a;

	int bestAns = 0;

	for(ll x = a; x <= n/2 && x < a + 500; x++) {
		ll amt1 = x;
		ll amt2 = n-x;
		amt1 = 5000*(amt1 / 5000 + 1) - amt1;
		amt2 = 5000*(amt2 / 5000 + 1) - amt2;
		amt1 %= 500;
		amt2 %= 500;

		bestAns = max((ll) bestAns, amt1 + amt2);
	}
	
	cout << bestAns << endl;

	return 0;
}