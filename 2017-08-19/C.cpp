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
		int N; cin >> N;
		ll cost = 0, size; cin >> size;
		cost += size;
		for(int i = 1; i < N; i++) {
			ll cur; cin >> cur;
			cost += cur;
			size = __gcd(size, cur);
		}

		cout << cost << " " << size << endl;
	}
	
	return 0;
}