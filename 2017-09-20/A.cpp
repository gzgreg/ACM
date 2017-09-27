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

	ll n, k; cin >> n >> k;
	ll origN = n;
	
	if(k == 0) {
		cout << n << endl;
	} else {
		int pow = 1;
		for(int i = 0; i < k; i++) {
			if(n % 2 == 0) {
				n /= 2;
			}
			if(n % 5 == 0) {
				n /= 5;
			}
			pow *= 10;
		}

		while(n % pow || n % origN) {
			n *= 10;
		}

		cout << n << endl;
	}
	
	return 0;
}