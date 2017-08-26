#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e5;
int t[2 * MAX];
int lastJoke[2*MAX];
vector<unordered_map<int, int>> jokes;

int N, M;

void build() {  // build the tree
	jokes = vector<unordered_map<int, int>>(2*N, unordered_map<int, int>());
	memset(lastJoke, -1, sizeof lastJoke);
	memset(t, 0, sizeof t);
}

void modify(int l, int r, int joke, int time) { // update value in range [l, r)
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l&1) {
			t[l] = time;
			jokes[l][joke]++;
			lastJoke[l] = joke;
			l++;
		}
		if (r&1){
			r--;
			t[r] = time;
			jokes[r][joke]++;
			lastJoke[r] = joke;
		}
	}
}

bool query(int p) { //get value at position p
	int curLast = -1;
	int lastTime = -1;
	int oldP = p;
	for (p += N; p > 0; p >>= 1){
		if(t[p] > lastTime) {
			lastTime = t[p];
			curLast = lastJoke[p];
		}
	}
	if(curLast == -1) {
		return true;
	}
	p = oldP;
	int numHears = 0;
	for (p += N; p > 0; p >>= 1){
		numHears += jokes[p][curLast];
		if(numHears >= 2) return true;
	}

	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while(T--) {
		cin >> N >> M;
		build();

		for(int i = 0; i < M; i++) {
			int xi, li, ki; cin >> xi >> li >> ki;
			xi--;

			modify(max(0, xi - ki), min(N, xi + ki + 1), li, i);
		}
		int ans = 0;
		for(int i = 0; i < N; i++) {
			ans += query(i);
		}
		cout << ans << endl;
	}
	
	return 0;
}