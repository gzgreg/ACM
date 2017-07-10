#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	
	int n, m, k; cin >> n >> m >> k;

	vector<vector<int>> con(n);
	vector<int> indeg(n, 0);

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		con[a-1].push_back(b-1);
		con[b-1].push_back(a-1);
	}

	set<int> bribes;
	map<int, int> costs;
	for(int i = 0; i < k; i++) {
		int id, ai; cin >> id >> ai;
		bribes.insert(id-1);
		costs[id-1] = ai;
	}
	for(int currId : bribes) {
		for(int conn : con[currId]) {
			indeg[conn]++;
		}
	}

	ld ans = 0;

	for(int currId : bribes) {
		ld a = costs[currId];
		ld valPerUp = 0;
		for(int j = 0; j < con[currId].size(); j++) {
			if(bribes.count(con[currId][j])) continue;
			valPerUp += 100.0/indeg[con[currId][j]];
		}
		int targetR = 0;
		while(targetR < 10) {
			if((valPerUp * targetR) - targetR*targetR*a*a
				> (valPerUp * (targetR + 1)) - (targetR+1)*(targetR+1)*a*a) {
				break;
			}
			targetR++;
		}
		ans += (valPerUp * targetR) - targetR*targetR*a*a;
	}

	cout << fixed << setprecision(10) << ans << endl;

	return 0;
}