#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pii> Hlist, Glist;
int H, G; 
ll memo[1011][1011][2];

ll dist (pii loc1, pii loc2) {
	int dx = loc1.first - loc2.first;
	int dy = loc1.second - loc2.second;
	return dx*dx + dy*dy;
}

ll dp(int Hidx, int Gidx, bool hLast) {
	if(Hidx == H && Gidx < G) {
		return 1e15;
	} else if (Hidx == H && Gidx == G) {
		return 0;
	} else if (memo[Hidx][Gidx][hLast] != -1) {
		return memo[Hidx][Gidx][hLast];
	}
	pii prev;
	if(hLast) {
		prev = Hlist[Hidx - 1];
	} else {
		prev = Glist[Gidx - 1];
	}

	return memo[Hidx][Gidx][hLast] = 
		Gidx < G ? 
			min(dp(Hidx + 1, Gidx, 1) + dist(prev, Hlist[Hidx]),
			dp(Hidx, Gidx + 1, 0) + dist(prev, Glist[Gidx]))
			: dp(Hidx + 1, Gidx, 1) + dist(prev, Hlist[Hidx]);
}

int main(){
	freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w", stdout);

	cin >> H >> G;
	
	memset(memo, -1, sizeof memo);
	
	for(int i = 0; i < H; i++) {
		int a, b; cin >> a >> b; Hlist.push_back({a, b});
	}

	for(int i = 0; i < G; i++) {
		int a, b; cin >> a >> b; Glist.push_back({a, b});
	}
	cout << dp(1, 0, 1) << endl;

	return 0;
}