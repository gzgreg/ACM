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
		int a, b; cin >> a >> b;
		if(a >= b) {
			cout << "FunkyMonkeys" << endl;
		} else {
			cout << "WeWillEatYou" << endl;
		}
	}
	
	return 0;
}