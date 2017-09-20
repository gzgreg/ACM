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

	int n, x; cin >> n >> x;
	
	if(n == 2 && x == 0) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	if(n == 1) {
		cout << x << endl;
	} else if (n == 2) {
		cout << 0 << " " << x << endl;
	} else {
		for(int i = 3; i < n; i++) {
			cout << i << " ";
			x ^= i;
		}

		cout << (1 << 17) << " " << ((1 << 18) + 2)<< " " << (x^(1 << 17)^((1 << 18) + 2)) << endl;
	}

	return 0;
}