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
		cout << "Case #" << id << ": ";

		int N, M, K; cin >> N >> M >> K;

		vector<vector<ll>> dist (N+1, vector<ll>(N+1, 2e11));

		for(int i = 0; i <= N; i++) {
			dist[i][i] = 0;
		}

		for(int i = 0; i < M; i++) {
			ll Ai, Bi, Gi; cin >> Ai >> Bi >> Gi;
			dist[Ai][Bi] = min(dist[Ai][Bi], Gi);
			dist[Bi][Ai] = min(dist[Bi][Ai], Gi);
		}

		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				for(int k = 1; k <= N; k++) {
					dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
				}
			}
		}

		vector<pii> trips;
		for(int i = 0; i < K; i++) {
			int Si, Di; cin >> Si >> Di; trips.push_back({Si, Di});
		}
		trips.push_back({1, 1});

		vector<vector<ll>> memo (K + 5, vector<ll>(2, 2e11));

		memo[0][0] = 0;

		for(int i = 1; i <= K; i++) {
			int lastStart = i == 1 ? 1 : trips[i-2].second;
			memo[i][0] = min(memo[i-1][0] + dist[trips[i-1].first][trips[i-1].second]
										  + dist[lastStart][trips[i-1].first],
							 memo[i-1][1] + dist[lastStart][trips[i-1].second]);
			memo[i][1] = min(memo[i-1][1] + dist[lastStart][trips[i].first]
									+ dist[trips[i].first][trips[i-1].second],
							 memo[i-1][0] + dist[lastStart][trips[i-1].first]
							 			  + dist[trips[i-1].first][trips[i].first]
							 			  + dist[trips[i].first][trips[i-1].second]);
		}
		

		// for(int i = 0; i < K+1; i++) {
		// 	for(int j = 0; j < 2; j++) {
		// 		cout << memo[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		cout << (memo[K][0] < 1.99e11 ? memo[K][0] : -1) << endl;

	}
	
	return 0;
}