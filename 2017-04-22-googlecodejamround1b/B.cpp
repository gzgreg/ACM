#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<pair<vi, int>, bool> memo;

string dict = "ROYGBV";

bool good(int i, int j) {
	bool valid = true;
	switch(j) {
		case 0:
			if(i == 0 || i == 1 || i == 5) valid = false;
			break;
		case 1:
			if(i != 4) valid = false;
			break;
		case 2:
			if(i == 1 || i == 2 || i == 3) valid = false;
			break;
		case 3:
			if(i != 0) valid = false;
			break;
		case 4:
			if(i == 3 || i == 4 || i == 5) valid = false;
			break;
		case 5:
			if(i != 2) valid = false;
			break;
	}
	return valid;
}

bool dp(vector<int> colors, int prev, int init) {
	if(memo.count({colors, prev})) {
		return memo[{colors, prev}];
	}

	int colorSum = 0;
	for(int color : colors) {
		colorSum += color;
	}
	if(colorSum == 1) {
		for(int i = 0; i < 6; i++) {
			if(colors[i] != 0) {
				if(good(i, init) && good(i, prev)) {
					memo[{{0, 0, 0, 0, 0, 0}, i}] = true;
					memo[{colors, prev}] = true;
					return true;
				} else {
					memo[{colors, prev}] = false;
					return false;
				}
			}
		}
	}
	vector<int> tmp(colors);
	sort(tmp.begin(), tmp.end());
	if(tmp[5] > tmp[4] + tmp[3] + tmp[2] + tmp[1] + tmp[0] + 1) {
		return memo[{colors, prev}] = false;
	}
	for(int i = 0; i < 6; i++) {
		if(colors[i] != 0) {
			if(!good(i, prev)) continue;
			vector<int> newColors(colors);
			newColors[i]--;
			if(dp(newColors, i, init)) {
				memo[{colors, prev}] = true;
				return true;
			}
		}
	}
	return memo[{colors, prev}] = false;
}

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;

	for(int id = 1; id <= T; id++) {
		cout << "Case #" << id << ": ";

		memo.clear();

		int N, R, O, Y, G, B, V; cin >> N >> R >> O >> Y >> G >> B >> V;
		vector<int> colors = {R, O, Y, G, B, V};
		for(int i = 0; i < 6; i++) {
			if(colors[i] != 0) {
				vi newColors(colors);
				newColors[i]--;
				dp(newColors, i, i);
				bool found = false;
				string s;
				for(int i = 0; i < 6; i++) {
					s = "";
					vector<int> currColors = {0, 0, 0, 0, 0, 0};
					if(memo[{currColors, i}]) {
						while(memo[{currColors, i}] && currColors != colors) {
							s.push_back(dict[i]);
							currColors[i]++;
							for(int j = 0; j < 6; j++) {
								if(memo[{currColors, j}]) {
									i = j;
									break;
								}
							}
						}
						if(colors == currColors) {
							cout << s << endl;
							found = true;
							break;
						}
					}
				}
				if (!found) cout << "IMPOSSIBLE" << endl;
				break;
			}
		}
	}
	
	return 0;
}