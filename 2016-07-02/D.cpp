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
		int last; cin >> last;
		bool boring = false;
		for(int i = 0; i < n-1; i++) {
			int curr; cin >> curr;
			if(curr == last){
				boring = true;
			}
			last = curr;
		}
		if(boring) {
			cout << "boring" << endl;
		} else {
			cout << "non-boring" << endl;
		}
	}
	

	return 0;
}