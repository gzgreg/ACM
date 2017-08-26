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
	set<char> letters = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
	int T; cin >> T;
	while(T--) {
		string S; cin >> S;
		int ans = 0;
		for(int i = 0; i < S.size(); i++) {
			for(int j = 0; j <= i && i + j < S.size(); j++) {
				if(letters.count(S[i-j])
					&& S[i-j] == S[i+j]) {
					ans = max(ans, 1 + 2*j);
				} else {
					break;
				}
			}

			for(int j = 0; j <= i && i + j + 1 < S.size(); j++) {
				if(letters.count(S[i-j])
					&& S[i-j] == S[i+j+1]) {
					ans = max(ans, 2 + 2*j);
				} else {
					break;
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}