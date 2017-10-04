#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int r, c, r0, c0, D, N;
	cin >> r >> c >> r0 >> c0 >> D >> N;

	int r1, r2, r3, r4, c1, c2, c3, c4;
	cin >> r1 >> c1 >> r2 >> c2;
	cin >> r3 >> c3 >> r4 >> c4;

	if(r1 > r2) swap(r1, r2);
	if(c1 > c2) swap(c1, c2);
	if(r3 > r4) swap(r3, r4);
	if(c3 > c4) swap(c3, c4);

	r0--; c0--;
	r1--; r2--; r3--; r4--;
	c1--; c2--; c3--; c4--;

	vector<vector<int>> chickens (r, vector<int>(c));

	for(int i = 0; i < N; i++) {
		int x, y; cin >> x >> y; 
		x--; y--;
		chickens[x][y]++;
	}

	int ans = 0;

	pii start = {r0, c0};

	queue<pii> bfsq;
	bfsq.push(start);
	map<pii, int> dist;
	dist[start] = 0;
	ans += chickens[r0][c0];
	while(!bfsq.empty()) {
		pii curr = bfsq.front(); bfsq.pop();
		vector<pii> nextAll {{curr.first-1, curr.second},
							{curr.first+1, curr.second},
							{curr.first, curr.second-1},
							{curr.first, curr.second+1}};
		for(pii next : nextAll) {
			if(next.first < 0 || next.first >= r) continue;
			if(next.second < 0 || next.second >= c) continue;
			
			if(next.first >= r1 && next.first <= r2
				&& next.second >= c1 && next.second <= c2) continue;

			if(next.first >= r3 && next.first <= r4
				&& next.second >= c3 && next.second <= c4) continue;

			if(dist.count(next)) continue;
			dist[next] = dist[curr] + 1;
			bfsq.push(next);
			if(dist[next] <= D) {
				ans += chickens[next.first][next.second];
			}
		}
	}

	cout << ans << endl;

	return 0;
}