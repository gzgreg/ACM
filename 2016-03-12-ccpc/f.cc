#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		int n,l,m; cin >> n >> l >> m;
		map<string,bool> dict;
		vector<string> inp;
		for (int i=0; i<n; i++) {
			string s; cin >> s;
			inp.push_back(s);
			dict[s] = true;
		}
		vector<map<string,int>> dicts;
		
		for (int i=0; i<l; i++) {
			map<string,int> tmp;
			for (int j=0; j<n; j++) {
				string tmps = inp[j];
				tmp[tmps.erase(i,1)]++;
			}
			dicts.push_back(tmp);
		}
		for (int k=0; k<m; k++) {
			string s; cin >> s;
			if (dict[s] == true) {
				cout << "correct spelling" << endl;
			} else {
				int ans = 0;
				for (int i=0; i<l; i++) {
					string curr = s;
					curr.erase(i,1);
					ans += dicts[i][curr];
				}
				cout << ans << " suggestion(s)" << endl;
			}
			
		}
	}
	return 0;
}