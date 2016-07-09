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
	while(T--){
		int curr, last = 1, ans = 0;
		cin >> curr; cin >> curr;
		while(curr != 0){
			if(curr > last * 2){
				ans += curr - last * 2;
			}
			last = curr;
			cin >> curr;
		}
		cout << ans << endl;
	}
	
	return 0;
}