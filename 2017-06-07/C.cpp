#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vector<int>> memo (26, vector<int>(1501, -1));

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;
	string s; cin >> s;
	for(int id = 0; id < 26; id++) {
		for(int i = 0; i <= n; i++) {
			int maxVal = 0;
			int num = i;
			int l = 0;
			int r = 0;
			for(int l = 0; r < n; l++) {
				while(num > 0 && r < n) {
					if(s[r] != id + 'a') num--;
					r++;
				}
				while(num == 0 && s[r] == id + 'a') {
					r++;
				}
				maxVal = max(maxVal, r-l);
				if(s[l] != id + 'a') num++;
			}
			memo[id][i] = maxVal;
		}
	}
	

	int q; cin >> q;
	while(q--) {
		int i; cin >> i;
		char c; cin >> c;

		cout << memo[c-'a'][i] << endl;
	}
	
	return 0;
}