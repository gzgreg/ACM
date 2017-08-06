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
	
	int N, R; cin >> N >> R;
	set<int> vals;
	for(int i = 1; i <= N; i++) {
		vals.insert(i);
	}

	for(int i = 0; i < R; i++) {
		int curr; cin >> curr; vals.erase(curr);
	}

	if(N == R) {
		cout << "*" << endl;
		return 0;
	}

	for(int i : vals) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}