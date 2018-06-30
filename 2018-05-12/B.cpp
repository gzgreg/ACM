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
		string a, b; cin >> a >> b;

		map<char, int> achars, bchars;

		for(auto cur : a) {
			achars[cur]++;
		}
		for(auto cur : b) {
			bchars[cur]++;
		}
		int ans = 0;
		for(auto cur : a) {
			if(bchars[cur] > 0) {
				bchars[cur]--;
				ans++;
			} else break;
		}

		cout << ans << endl;
	}
	
	return 0;
}