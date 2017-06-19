#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x; cin >> n >> x;
	vector<int> jumps;
	for(int i = 0; i < n; i++) {
		int curr; cin >> curr; jumps.push_back(curr);
	}

	int jump = jumps[0];
	for(int i = 1; i < n; i++) {
		jump = __gcd(jump, jumps[i]);
	}

	if(x < 0) x = -x;

	cout << (x % jump == 0 ? "YES" : "NO") << endl;
	
	return 0;
}