#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		ld val = cbrt((ld)a*b);
		if(abs(val - floor(val + 1e-8)) < 1e-7) {
			ll cur1 = __gcd((ll)a*a, (ll)b);
			ll cur2 = __gcd((ll)a, (ll)b*b);
			if(cur1 == b && cur2 == a) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		} else {
			cout << "No" << endl;
		}

		//cout << (bad ? "No" : "Yes") << endl;
	}
	
	return 0;
}