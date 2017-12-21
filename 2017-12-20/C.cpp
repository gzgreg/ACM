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

	ll P1, P2; cin >> P1 >> P2;
	if(P1 == P2 && P2 == 0) {
		cout << "0 0" << endl;
		return 0;
	}
	for(int i = 0; i < 10000; i++) {
		ll cur = P1 - P2;
		if(cur < 0) {
			cout << i+3 << " " << cur << endl;
			return 0;
		}
		P1 = P2; 
		P2 = cur;
	}
	
	return 0;
}