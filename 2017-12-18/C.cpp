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

	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		if(n % 3 == 0) {
			cout << n/3 << " " << n/3 << " " << n/3 << endl;
		} else if (n % 4 == 0) {
			cout << n/2 << " " << n/4 << " " << n/4 << endl;
		} else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	
	return 0;
}