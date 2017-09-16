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
	
	int n, k, t; cin >> n >> k >> t;

	if(t < k) {
		cout << t << endl;
	} else if (t > n) {
		cout << (n + k - t) << endl;
	} else {
		cout << k << endl;
	}

	return 0;
}