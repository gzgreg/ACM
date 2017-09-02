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
	
	int n, w, h; cin >> n >> w >> h;

	vector<pii> endPos;
	vector<vi> horz, vert;

	for(int i = 0; i < n; i++) {
		int gi, pi, ti; cin >> gi >> pi >> ti;

		if(gi == 1) {
			endPos.push_back({pi, h});
			vert.push_back({pi - ti, pi, i});
		} else {
			endPos.push_back({w, pi});
			horz.push_back({pi - ti, pi, i});
		}
	}

	sort(vert.begin(), vert.end());
	sort(horz.begin(), horz.end());

	int horzI = 0, vertI = 0;
	set<pii> horzIndex, vertIndex;

	vector<pii> ans(endPos);

	auto solve = [&]() {
		vector<int> vals;
		for(auto it = horzIndex.rbegin(); it != horzIndex.rend(); it++) {
			vals.push_back(it->second);
		}

		for(pii i : vertIndex) {
			vals.push_back(i.second);
		}

		for(int i = 0; i < vals.size(); i++) {
			int pos1 = vals[i];
			int pos2 = vals[(i + vertIndex.size()) % vals.size()];
			ans[pos2] = endPos[pos1];
		}

		horzIndex.clear();
		vertIndex.clear();
	};
	while(horzI < horz.size() && vertI < vert.size()) {
		if(horz[horzI][0] == vert[vertI][0]) {
			horzIndex.insert({horzI, horz[horzI][2]});
			vertIndex.insert({vertI, vert[vertI][2]});
			horzI++;
			if(horzI >= horz.size() || horz[horzI][0] > vert[vertI][0]) {
				horzI--;
				vertI++;
			}
			continue;
		} else if (horzIndex.size() > 0) {
			solve();
		}

		if (horz[horzI][0] > vert[vertI][0]) {
			vertI++;
		} else {
			horzI++;
		}
	}

	if (horzIndex.size() > 0) {
		solve();
	}

	for(pii cur : ans) {
		cout << cur.first << " " << cur.second << endl;
	}

	return 0;
}