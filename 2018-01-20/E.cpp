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
	
	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;

		cout << fixed << setprecision(10) << max(0.0, (double) (n-m) / (n+m)) << endl;
	}

	return 0;
}