#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, C, t1, t2;
vector<int> dist;

int memo[1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> C >> t1 >> t2;
	
	for(int i = 0; i < N; i++) {
		int curr; cin >> curr; dist.push_back(curr);
	}

	sort(dist.begin(), dist.end());

	for(int i = 1; i < N; i++) {
		dist[i] -= dist[0];
	}
	dist[0] = 0;

	int bestAns = 1e7;

	for(int i = 0; i < N; i++) {
		memset(memo, -1, sizeof memo);
		int id1 = N-1, id2 = N-1;
		for(int j = N; j >= 0; j--) {
			if(j == N) {
				memo[j] = 0;
				continue;
			}
			while(dist[j] + t1 < dist[id1]) {
				id1--;
			}
			while(dist[j] + t2 < dist[id2]) {
				id2--;
			}
			memo[j] = min(memo[id1 + 1] + t1, memo[id2 + 1] + t2);
		}
		bestAns = min(bestAns, memo[0]);
		rotate(dist.begin(), dist.begin() + 1, dist.end());
		for(int j = 1; j < N; j++) {
			dist[j] -= dist[0];
		}
		dist[0] = 0;
		dist[N-1] += C;
	}

	cout << bestAns << endl;
	
	return 0;
}