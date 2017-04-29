#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	
	int n, k; cin >> n >> k;
	vector<ll> a;
	for(int i = 0; i < n; i++) {
		int curr; cin >> curr; a.push_back(curr);
	}
	ll minVal = a[0];
	for(int i = 1; i < n; i++) {
		if(a[i] % k != a[0] % k) {
			cout << -1 << endl;
			return 0;
		} else {
			minVal = min(minVal, a[i]);
		}
	}
	ll totTime = 0;

	for(int i = 0; i < n; i++) {
		totTime += (a[i] - minVal) / k;
	}

	cout << totTime << endl;

	return 0;
}