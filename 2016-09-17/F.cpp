#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

regex numSeq ("[0-9A-Z]+", regex_constants::basic);
smatch a;

int main(){
	ios::sync_with_stdio(0);

	vector<bool> seenNum (1e7, false);
	seenNum[0] = true;
	int complete = 0;

	int m; cin >> m;

	for(int i = 1; i <= m; i++) {
		int k, w; cin >> k >> w;

		for(int i = 0; i < k; i++) {
			string sign; getline(cin, sign);
			set<int> seenNums;
			while(regex_search(sign, a, numSeq)) {
				cout << "start";
				for(auto x : a) cout << x << " ";
				cout << endl;
			}
		}

		cout << "Case " << i << ": ";
	}
	
	return 0;
}