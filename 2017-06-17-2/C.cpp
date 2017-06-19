#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c, n, m; cin >> a >> b >> c >> n >> m;

	int ans;
	if(a + c <= n && b + c <= m) {
		ans = a + b + c;
	} else if (a + c > n && b + c <= m) {
		ans = n;
	} else if (b + c > m && a + c <= n) {
		ans = m;
	} else {
		ans = min(n, m);
	}

	cout << ans << endl;
	
	return 0;
}