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

	int P; cin >> P;
	while(P--) {
		int junk; cin >> junk;
		string s; cin >> s;

		bool found = false;
		for(int i = 0; i < s.size() - 1; i++) {
			if(s[i] < s[i+1]) {
				next_permutation(s.begin(), s.end());
				cout << junk << " " << s << endl;
				found = true;
				break;
			}
		}
		if(!found) {
			cout << junk << " " << "BIGGEST" << endl;
		}

	}
	
	return 0;
}