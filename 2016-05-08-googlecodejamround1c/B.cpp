#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pii;
typedef vector<long long> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	long long T; cin >> T;
	for(long long idx = 1; idx <= T; idx++){
		cout << "Case #" << idx << ": ";

		long long B, M; cin >> B >> M;

		if(pow(2, B - 2) < M){
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		long long adj[B][B];
		memset(adj, 0, sizeof adj);
		for(long long j = 0; j < B; j++){
			for(long long k = j+1; k < B; k++){
				adj[j][k] = 1;
			}
		}
		for(long long j = 1; j < B; j++){
			adj[j][B-1] = ((M - 1)>> (j - 1)) & 1;
		}
		cout << "POSSIBLE" << endl;
		for(long long j = 0; j < B; j++){
			for(long long k = 0; k < B; k++){
				cout << adj[j][k];
			}
			cout << endl;
		}
	}
	
	return 0;
}