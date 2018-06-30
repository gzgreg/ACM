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
		int N, M; cin >> N >> M;

		if(N % 2 || M % 2) {
			cout << "hasan" << endl;
		} else {
			cout << "abdullah" << endl;
		}
	}
	
	return 0;
}