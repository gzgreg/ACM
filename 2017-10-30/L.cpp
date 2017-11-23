#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int invert(int i) {
	bitset<3> cur(i);
	for (int i = 0; i < 3; i++) {
		cur[i] = !cur[i];
	}

	return cur.to_ulong();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;

	vector<vector<int>> assn(3, vector<int>(n));

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < n; j++) {
			cin >> assn[i][j];
		}
	}

	map<int, vector<int>> identical;

	for(int i = 0; i < n; i++) {
		int val = (assn[0][i] << 2) + (assn[1][i] << 1) + assn[2][i];
		identical[val].push_back(i);
	}

	vector<bool> vis(8);
	for(auto cur : identical) {
		vis[cur.first] = true;
	}

	int numResults = 0;
	for(int i = 0; i < (1 << 8); i++) {
		auto cur = bitset<8>(i);
		bool good = true;
		for(int j = 0; j < 8; j++) {
			if(!vis[j] && cur[j]) {
				good = false;
				break;
			}
		}
		if(!good) continue;
		for(int j = 0; j < 8; j++) {
			if(!vis[j]) continue;
			for(int k = 0; k < 8; k++) {
				if(!vis[k]) continue;
				if(invert(invert(j) | k) == 0) {
					// j -> k
					if(cur[j] && !cur[k]) {
						good = false;
						break;
					}
				} 
				if (invert(j | k) == 0) {
					// !j -> k
					if(!cur[j] && !cur[k]) {
						good = false;
						break;
					}
				} 
				if(invert(invert(j) | invert(k)) == 0) {
					// j -> !k
					if(cur[j] && cur[k]) {
						good = false;
						break;
					}
				} 
				if (invert(j | invert(k)) == 0) {
					// !j -> !k
					if(!cur[j] && cur[k]) {
						good = false;
						break;
					}
				}
			}
			if(!good) break;
		}
		if(good) {
			//cout << cur <<  endl;
			numResults++;
		}
	}
	if(numResults > 3) { 
		cout << -1 << endl;
		return 0;
	}

	vector<pair<pair<int, bool>, pair<int, bool>>> impl;
	for(int j = 0; j < 8; j++) {
		if(!vis[j]) continue;
		for(int k = 0; k < 8; k++) {
			if(!vis[k]) continue;
			if(j == k) continue;
			int rep1 = identical[j][0];
			int rep2 = identical[k][0];
			if(invert(invert(j) | k) == 0) {
				// j -> k
				impl.push_back({{rep1, true}, {rep2, true}});
			} 
			if (invert(j | k) == 0) {
				// !j -> k
				impl.push_back({{rep1, false}, {rep2, true}});
			} 
			if(invert(invert(j) | invert(k)) == 0) {
				// j -> !k
				impl.push_back({{rep1, true}, {rep2, false}});
			} 
			if (invert(j | invert(k)) == 0) {
				// !j -> !k
				impl.push_back({{rep1, false}, {rep2, false}});
			}
		}
	}

	for(auto cur : identical) {
		vector<int> matching = cur.second;
		for(int i = 1; i < matching.size(); i++) {
			impl.push_back({{matching[0], true}, {matching[i], true}});
			impl.push_back({{matching[i], true}, {matching[0], true}});
		}
	}

	cout << impl.size() << endl;
	for(auto cur : impl) {
		if(!cur.first.second) cout << "!";
		cout << "x";
		cout << cur.first.first + 1;
		cout << " -> ";
		if(!cur.second.second) cout << "!";
		cout << "x";
		cout << cur.second.first + 1;
		cout << endl;
	}
	return 0;
}