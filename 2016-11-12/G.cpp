#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	
	int N; cin >> N;
	while(N--) {
		int M; cin >> M;

		set<pair<int, string>, greater<pair<int, string>>> players;

		for(int i = 0; i < 1 << M; i++) {
			string s; cin >> s;
			int num; cin >> num;
			players.insert({num, s});
		}

		int R = 3*M - (players.begin())->first;

		int round = M;
		vector<set<string>> names (11, set<string>());

		for(pair<int, string> player : players) {
			if(player.first >= 2*min(R, round) + 3*max(round-R, 0)) {
				names[round].insert(player.second);
			} else {
				round--;
				names[round].insert(player.second);
			}
		}

		for(int i = names.size() - 1; i >= 0; i--) {
			for(string name : names[i]) {
				cout << name << endl;
			}
		}
	}

	return 0;
}