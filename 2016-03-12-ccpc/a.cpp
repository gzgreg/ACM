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
		int n; cin >> n;
		vector<pair<int, int> > instr;
		for (int i=0; i<n; i++) {
			string s; cin >> s;
			if(s[0] == 'N'){
				instr.push_back(make_pair(0, 0));
			} else {
				int l; cin >> l; l--;
				if(s[0] == 'C'){
					instr.push_back(make_pair(1, l));
				} else {
					instr.push_back(make_pair(2, l));
				}
			}
		}

		bool seen[n];
		memset(seen, false, sizeof seen);
		queue<int> q;
		q.push(0);
		while(!q.empty()) {
			int curr = q.front();
			q.pop();
			if (!seen[curr]) {
				seen[curr] = true;
				int i = instr[curr].first;
				if (i != 2) {
					if (curr != n-1) q.push(curr+1);
				}
				if (i != 0) {
					q.push(instr[curr].second);
				}
			}
		}
		for (int i=0; i<n; i++) {
			if (seen[i]) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}


	return 0;
}