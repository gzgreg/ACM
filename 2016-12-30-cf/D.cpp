#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;
	vector<int> dists;
	for(int i = 0; i < n; i++) {
		int dist; cin >> dist; dists.push_back(dist);
	}

	set<pair<pii, pii>> frags;
	set<pii> locs;

	frags.insert({{0, 0}, {0, dists[0]}});
	vector<pii> dirs = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
	for(int i = 0; i < n; i++) {
		set<pair<pii, pii>> newFrags;
		for(pair<pii, pii> frag : frags) {
			pii loc = frag.first;
			pii vec = frag.second;

			for(int i = 1; i <= vec.second; i++) {
				int newX = loc.first + dirs[vec.first].first * i;
				int newY = loc.second + dirs[vec.first].second * i;
				locs.insert({newX, newY});
			}

			if(i < n-1) {
				int newDir = (vec.first + 1) % 8;
				pii newLoc = {loc.first + dirs[vec.first].first * vec.second,
								loc.second + dirs[vec.first].second * vec.second};
				newFrags.insert({newLoc, {newDir, dists[i+1]}});
				newDir = (vec.first + 7) % 8;
				newFrags.insert({newLoc, {newDir, dists[i+1]}});
			}
		}
		frags = newFrags;
	}

	cout << locs.size() << endl;
	
	return 0;
}