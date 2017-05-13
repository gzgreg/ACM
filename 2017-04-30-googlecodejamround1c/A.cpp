#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define PI 3.141592653
vector<pii> cakes;
vector<vector<vector<double>>> memo;
int N, K;

double dp(int id, int Ki, bool first) {
	if(id == cakes.size()-1 && Ki > 0) {
		return memo[id][Ki][first] 
			= 2*PI*cakes[id].first*cakes[id].second 
			+ first*PI*cakes[id].first*cakes[id].first;
	}
	if(id == cakes.size()-1 && Ki == 0) {
		return memo[id][Ki][first] = 0;
	}
	if(memo[id][Ki][first] != -1) {
		return memo[id][Ki][first];
	}
	if(Ki == 0) {
		return memo[id][Ki][first] = dp(id+1, Ki, first);
	}
	double maxHeight = 0;
	maxHeight = max(dp(id+1, Ki, first), 
		dp(id+1, Ki-1, false) + 
		2*PI*cakes[id].first*cakes[id].second + 
		first*PI*cakes[id].first*cakes[id].first);

	return memo[id][Ki][first] = maxHeight;
}

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;

	for(int id = 1; id <= T; id++) {
		cout << "Case #" << id << ": ";
		cin >> N >> K;
		cakes.clear();
		memo = vector<vector<vector<double>>>(N+1, vector<vector<double>>(K+1, vector<double>(2, -1)));

		for(int i = 0; i < N; i++) {
			int Ri, Hi; cin >> Ri >> Hi; cakes.push_back({Ri, Hi});
		}

		sort(cakes.begin(), cakes.end());
		reverse(cakes.begin(), cakes.end());

		cout << fixed << setprecision(10) << dp(0, K, true) << endl;
		// for(int i = 0; i <=N; i++) {
		// 	for(int j = 0; j <= K; j++) {
		// 		cout << memo[i][j][0] <<  " ";
		// 	}
		// 	cout << endl;
		// }
	}
	
	return 0;
}