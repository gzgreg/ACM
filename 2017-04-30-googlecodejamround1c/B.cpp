#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int memo[721][721][2];
bool C[1441], J[1441];

int dp(int minC, int minJ, bool isC) {
	int currTime = 1440 - minC - minJ;

	if(minC == 0 && minJ == 0) {
		return 0;
	} else if (memo[minC][minJ][isC] != -1) {
		return memo[minC][minJ][isC];
	} else if (minC == 0) {
		return J[currTime] ? 1e8 : dp(minC, minJ - 1, false) + isC;
	} else if (minJ == 0) {
		return C[currTime] ? 1e8 : dp(minC - 1, minJ, true) + !isC;
	}

	int minVal = 1e8;
	bool canDo = !C[currTime];
	if(canDo) minVal = min(minVal, dp(minC - 1, minJ, true) + !isC);

	canDo = !J[currTime];
	if(canDo) minVal = min(minVal, dp(minC, minJ - 1, false) + isC);
	return memo[minC][minJ][isC] = minVal;
}

int main(){
	ios::sync_with_stdio(0);
	
	int T; cin >> T;

	for(int id = 1; id <= T; id++) {
		cout << "Case #" << id << ": ";

		int Ac, Aj; cin >> Ac >> Aj;

		memset(C, 0, sizeof C);
		for(int i = 0; i < Ac; i++) {
			int Ci, Di; cin >> Ci >> Di;
			for(int i = Ci; i < Di; i++) {
				C[i] = true;
			}
		}
		memset(J, 0, sizeof J);
		for(int i = 0; i < Aj; i++) {
			int Ci, Di; cin >> Ci >> Di;
			for(int i = Ci; i < Di; i++) {
				J[i] = true;
			}
		}
		memset(memo, -1, sizeof memo);
		int minVal = 1e8;
		int val = dp(720, 720, false);
		if(val % 2) val++;
		minVal = min(minVal, val);
		val = dp(720, 720, true);
		if(val % 2) val++;
		minVal = min(minVal, val);
		cout << minVal << endl;
	}

	return 0;
}