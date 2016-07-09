#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	
	int T; cin >> T;
	while(T--){
		int N; cin >> N;
		vector<int> players;
		for(int i = 0; i < 2*N; i++){
			int curr; cin >> curr; players.push_back(curr);
		}

		sort(players.begin(), players.end());

		int minVal = 10000000;
		for(int i = 0; i < N; i++){
			int val = max(players[N+i-1] - players[0], players[2*N-1] - players[i]);
			minVal = min(minVal, val);
		}
		cout << minVal << endl; 
	}

	return 0;
}