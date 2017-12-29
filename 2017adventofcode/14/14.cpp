#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

set<pii> seen;

map<pii, int> grid;

int dfs(pii cur) {
	if(seen.count(cur)) return 0;
	if(grid[cur] == 0) return 0;
	seen.insert(cur);
	for(int i = -1; i <= 1; i += 2) {
		dfs({cur.first, cur.second + i});
		dfs({cur.first + i, cur.second});
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s; cin >> s;

	int tot = 0;
	for(int i = 0; i < 128; i++) {
		string curS = s;
		curS.push_back('-');
		curS.append(to_string(i));
		vector<int> out;

		for(int i = 0; i < 256; i++) {
			out.push_back(i);
		}
		vector<int> vals;
		for(int i = 0; i < curS.size(); i++) {
			vals.push_back(curS[i]);
		}
		vals.push_back(17);
		vals.push_back(31);
		vals.push_back(73);
		vals.push_back(47);
		vals.push_back(23);
		int start = 0, skip = 0;
		for(int it = 0; it < 64; it++) {
			for(int i = 0; i < vals.size(); i++) {
				reverse(out.begin(), out.begin() + vals[i]);
				rotate(out.begin(), out.begin() + ((vals[i]+ skip) % out.size()), out.end());
				start += 100*out.size() - vals[i] - skip;
				start %= out.size();
				skip++;
			}
		}
		for(int k = 0; k < 16; k++) {
			int ans = 0;
			for(int j = k*16; j < k*16 + 16; j++) {
				ans ^= out[(j + start) % out.size()];
			}
			cout << bitset<8>(ans);
			tot += bitset<8>(ans).count();
			for(int j = 0; j < 4; j++) {
				grid[{i, 3-j + 8*k}] = bitset<8>(ans)[j+4];
				grid[{i, 7-j + 8*k}] = bitset<8>(ans)[j];
			}
		}
		cout << endl;
	}
	for(int i = 0; i < 128; i++) {
		cout << grid[{0, i}];
	}
	cout << endl;
	int p2 = 0;
	for(auto cur : grid) {
		p2 += dfs(cur.first);
	}
	cout << tot << endl;
	cout << p2 << endl;

	return 0;
}