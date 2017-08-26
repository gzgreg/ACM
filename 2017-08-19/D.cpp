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

		vector<int> h;
		for(int i = 0; i < N; i++) {
			int cur; cin >> cur; h.push_back(cur);
		}
		bool good = true;
		for(int i = 1; i < N; i++) {
			if(h[i] % 2 != h[0] % 2) {
				good = false;
				break;
			}
		}

		if(good) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
	
	return 0;
}