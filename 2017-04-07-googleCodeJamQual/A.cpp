#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	for(int id = 1; id <= T; id++) {
		string S; cin >> S;
		int K; cin >> K;
		int moves = 0;
		for(int i = 0; i < S.size() - K + 1; i++) {
			if(S[i] == '-') {
				for(int j = i; j < i+K; j++) {
					if(S[j] == '-') {
						S[j] = '+';
					} else {
						S[j] = '-';
					}
				}
				moves++;
			}
		}
		cout << "Case #" << id << ": ";
		for(int i = 0; i < S.size(); i++) {
			if(S[i] != '+') {
				cout << "IMPOSSIBLE" << endl;
				break;
			}
			if(i == S.size() - 1) {
				cout << moves << endl;
			}
		}
	}
	
	return 0;
}