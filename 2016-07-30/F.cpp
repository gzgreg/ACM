#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;
	while(n--) {
		long long li, ri; cin >> li >> ri;

		double ans = 1.0 / li - (1.0 / (ri + 1));

		cout << setprecision(10) << fixed << ans << endl;
	}
	
	return 0;
}