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
	
	string s; cin >> s;

	int ans = 0;
	for(auto cur : s) {
		if(cur == 'a' || cur == 'e'
			|| cur == 'i' || cur == 'o' || cur == 'u'
			|| cur == '1' || cur == '3' || cur == '5'
			|| cur == '7' || cur == '9') {
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}