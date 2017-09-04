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
	
	int N, X; cin >> N >> X;

	bool less = false, high = false;

	for(int i = 0; i < N; i++) {
		int cur; cin >> cur;
		if(cur == X) {
			cout << 1 << endl;
			return 0;
		}
		if(cur < X) {
			less = true;
		}
		if (cur > X) {
			high = true;
		}
	}

	if(less && high) {
		cout << 2 << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}