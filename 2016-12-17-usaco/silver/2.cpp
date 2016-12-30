#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);

	int N; cin >> N;

	map<string, map<string, int>> states;
	set<string> stateNames;

	for(int i = 0; i < N; i++) {
		string city, state; cin >> city >> state;
		states[state][city.substr(0, 2)]++;
		stateNames.insert(state);
	}
	long long specials = 0;
	for(string i : stateNames) {
		for(string j : stateNames) {
			if(i == j) continue;
			int cities1 = states[i][j];
			int cities2 = states[j][i];
			specials += cities2 * cities1;
		}
	}
	cout << specials / 2 << endl;
	return 0;
}