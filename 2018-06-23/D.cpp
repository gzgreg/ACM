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

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ll n, k; cin >> n >> k;
	ll num = 1;
	ll ans = 0;
	while(num < n) {
		num += num * k;
		ans++;
	}

	cout << ans << endl;

	
	return 0;
}