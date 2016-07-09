#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

void printvec(vector<bool> pile){
	// for(int i = 0; i < pile.size(); i++){
	// 	cout << pile[i];
	// }
	// cout << endl;
}

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	for(int o = 1; o <= T; o++){
		string s; cin >> s;

		vector<bool> pile;
		for(int i = 0; i < s.size(); i++){
			pile.push_back((s[i] == '+'));
		}
		auto bot = pile.end();
		int moves = 0;
		printvec(pile);
		while(bot != pile.begin()){
			if(*(--bot)){
				continue;
			} else {
				bot++;
			}
			auto top = pile.begin();
			while(*top){
				top++;
			}
			if(top != pile.begin()){
				moves++;
				reverse(pile.begin(), top);
				printvec(pile);
				for(auto it = pile.begin(); it != top; it++){
					*it = !(*it);
				}
				printvec(pile);
			}

			moves++;
			reverse(pile.begin(), bot);
			printvec(pile);
			for(auto it = pile.begin(); it != bot; it++){
				*it = !(*it);
			}

			printvec(pile);

			bot--;
		}
		cout << "Case #" << o << ": ";
		cout << moves << endl;
	}
	
	return 0;
}