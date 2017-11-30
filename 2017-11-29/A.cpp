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

	int n, k, x; cin >> n >> k >> x;

	int time = 0;
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur;
		if(i >= n-k) {
			time += x;
		} else {
			time += cur;
		}
	}
	
	cout << time << endl;

	return 0;
}