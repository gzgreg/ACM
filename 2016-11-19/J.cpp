#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

string s;

int memo[1 << 19 + 1][19];

bool getBit(int num, int idx) {
	return (num >> idx) & 1;
}

int dp(int state, int pos) {
	if(state == (1 << s.size()) - 1) {
		return 0;
	} else if(memo[state][pos] != -1) {
		return memo[state][pos];
	} else {
		int minAns = 100000000;
		int letter = pos > 0 ? s[pos-1] - 'A' : 0;
		for(int i = 0; i < s.size(); i++) {
			if(!getBit(state, i)) {
				int newState = state | (1 << i);
				int lRep = s[i] - 'A';
				int val = dp(newState, i+1);
				
				val += min(abs(lRep - letter), 26 - abs(lRep - letter));
				val++;
				for(int j = min(pos, i); j < max(pos, i); j++) {
					if(getBit(state, j)) val++;
				}

				minAns = min(minAns, val);
			}
		}

		memo[state][pos] = minAns;
		return minAns;
	}
}

int main(){
	ios::sync_with_stdio(0);

	cin >> s;

	while(s != "0") {
		memset(memo, -1, sizeof memo);
		cout << dp(0, 0) << endl;
		cin >> s;
	}
	
	return 0;
}