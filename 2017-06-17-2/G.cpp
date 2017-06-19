#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<string> names;
	for(int i = 0; i < n; i++) {
		string s; cin >> s; names.push_back(s);
	}

	vector<pii> ref (n, {0, 0});

	int m; cin >> m;
	for(int i = 0; i < m; i++) {
		int aj, bj; cin >> aj >> bj;
		aj--; bj--;
		if(ref[bj].first == 0) {
			ref[aj] = {1, bj};
		} else {
			ref[aj] = {ref[bj].first + 1, ref[bj].second};
		}
	}

	if(ref[0].first == 0) {
		cout << names[0] << endl;
		return 0;
	}

	for(int i = 0; i < ref[0].first; i++) {
		cout << "I_love_";
	}
	cout << names[ref[0].second] << endl;
	
	return 0;
}