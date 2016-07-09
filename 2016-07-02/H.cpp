#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		int score = 0;
		for(int i = 0; i < n; i++) {
			int x, y; cin >> x >> y;
			double dist = sqrt(x*x + y*y);
			score += min(max(0, 11-(int)ceil(dist/20)), 10);
		}
		cout << score << endl;
	}
	
	return 0;
}