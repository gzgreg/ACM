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

	int n; cin >> n;
	vector<int> angle;
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; angle.push_back(cur);
	}
	int res = 10000000;
	for(int i = 0; i < n; i++) {
		int ans = 0;
		for(int j = 0; j < n; j++) {
			if(angle[(i+j)%n] + ans <= 180) {
				ans += angle[(i+j)%n];
			} else {
				if(abs(180 - ans) > abs(180 - ans - angle[(i+j)%n])) {
					ans += angle[(i+j)%n];
				}
				break;
			}
		}
		if(2*abs(180 - ans) < 2*abs(180 - res)) {
			res = ans;
		}
	}

	cout << 2*abs(180 - res) << endl;
	
	return 0;
}