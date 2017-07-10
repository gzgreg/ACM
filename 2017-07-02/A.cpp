#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	int a, b; cin >> a >> b;
	int ans = 1;
	for(int i = 2; i <= min(a, b); i++) {
		ans *= i;
	}

	cout << ans << endl;
	
	return 0;
}