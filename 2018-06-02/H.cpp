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
		ld a, b, c, d; cin >> a >> b >> c >> d;
		if(log(a) * b < log(c) * d) cout << "<" << endl;
		else cout << ">" << endl;
	}

	return 0;
}