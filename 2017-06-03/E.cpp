#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vector<int>> memo;

int main(){
	ios::sync_with_stdio(0);

	int P; cin >> P;
	memo.push_back(vector<int>(100, 0));

	for(int i = 1; i <= 2000; i++) {
		vector<int> newState(memo[i-1]);
		for(int j = 0; j < newState.size(); j++) {
			if(newState[j] + (j + 1) == (j + 1)) {
				for(int k = 0; k < j; k++) {
					newState[k]--;
				}
				newState[j] += j + 1;
				memo.push_back(newState);
				break;
			}
		}
	}

	while(P--) {
		int K, B; cin >> K >> B;

		int lastNonZero;
		for(int i = 0; i < memo[B].size(); i++) {
			if(memo[B][i] != 0) {
				lastNonZero = i + 1;
			}
		}

		cout << K << " " << lastNonZero;
		for(int i = 0; i < lastNonZero; i++) {
			if(i % 10 == 0) cout << endl;
			cout << memo[B][i] << " ";
		}
		cout << endl;
	}

	
	return 0;
}