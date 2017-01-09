#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int n, m; cin >> n >> m;
	set<pii> arms;

	for(int i = 0; i < m; i++) {
		int xi, yi; cin >> xi >> yi; arms.insert({xi, yi - 1});
	}

	vector<pii> lanes (n, {1, 0});

	for(pii arm : arms) {
		int y = arm.second;
		int totalEls = lanes[y].first;
		totalEls += lanes[y+1].first - lanes[y].second;
		lanes[y] = {totalEls, totalEls};
		lanes[y+1] = {totalEls, lanes[y+1].second};
	}

	for(int i = 0; i < n; i++) {
		cout << lanes[i].first << " ";
	}
	cout << endl;
	
	return 0;
}