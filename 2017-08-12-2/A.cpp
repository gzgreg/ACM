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
	int ans = 0;
	int len = 0;
	while(len < n) {
		string s; cin >> s;
		len += s.size() + 1;
		int cur = 0;
		for(int j = 0; j < s.size(); j++) {
			if(s[j] >= 'A' && s[j] <= 'Z') {
				cur++;
			}
		}
		ans = max(ans, cur);
	}
	cout << ans << endl;
	
	return 0;
}