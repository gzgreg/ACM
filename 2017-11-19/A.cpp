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
	for(int i = 0; i < s.size(); i++) {
		for(int j = i+1; j < s.size(); j++) {
			for(int k = j+1; k < s.size(); k++) {
				if(s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') {
					ans++;
				}
			}
		}
	}

	cout << ans << endl;
	
	return 0;
}