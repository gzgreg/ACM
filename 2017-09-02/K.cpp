#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<int,int> vals;

int N, M;

int ans = 0;

int accum[10001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;

	for(int i = 0; i < N; i++) {
		int cur; cin >> cur; vals[cur]++;
		bitset<21> asdf(cur); cout  << asdf << endl;
	}
	memset(accum, 0, sizeof accum);

	queue<int> bfsq; bfsq.push(0); accum[0] = 0;
	int smaller = 0;
	int curLevel = 0;
	int curLevelAmt = 0;
	set<int> vis;
	while(!bfsq.empty()) {
		int cur = bfsq.front(); bfsq.pop();
		if(__builtin_popcount(cur) > curLevel) {
			curLevel = __builtin_popcount(cur);
			smaller += curLevelAmt;
			curLevelAmt = 1;
		} else {
			curLevelAmt++;
		}
		int toAdd = vals[cur];
		bitset<21> id(cur);
		for(int i = 0; i < M; i++) {
			if(!id[i]) {
				id.set(i);
				int out = id.to_ulong();
				accum[out] += toAdd;
				if(vis.count(out)) {
					id.reset(i);
					continue;
				}
				vis.insert(out);
				bfsq.push(out);
				id.reset(i);
			}
		}

		cout << cur << " " << (smaller - accum[cur] - vals[cur]) * vals[cur] << endl;
		ans += (N - accum[cur] - vals[cur]) * vals[cur];
	}
	ans /= 2;
	cout << ans << endl;

	return 0;
}