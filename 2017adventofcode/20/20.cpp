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
	
	string s;
	int ans = 0;

	vector<vector<vector<int>>> vals;
	int bestId;
	int best = 1e9;
	int bestV = 1e9;
	int bestP = 1e9;
	int i = 0;
	while(getline(cin, s)) {
		stringstream str(s);

		vector<int> p(3), v(3), a(3);
		char junk;
		str >> junk >> junk >> junk;
		for(int i = 0; i < 3; i++) {
			str >> p[i];
			str >> junk;
		}
		str >> junk;
		str >> junk;
		str >> junk >> junk;
		for(int i = 0; i < 3; i++) {
			str >> v[i];
			str >> junk;
		}
		str >> junk; str >> junk;
		str >> junk >> junk;
		for(int i = 0; i < 3; i++) {
			str >> a[i];
			str >> junk;
		}

		if(abs(a[0]) + abs(a[1]) + abs(a[2]) < best) {
			best = abs(a[0]) + abs(a[1]) + abs(a[2]);
			bestV = abs(v[0]) + abs(v[1]) + abs(v[2]);
			bestP = abs(p[0]) + abs(p[1]) + abs(p[2]);
			bestId = i;
		} else if (abs(a[0]) + abs(a[1]) + abs(a[2]) == best) {
			if(abs(v[0]) + abs(v[1]) + abs(v[2]) < bestV) {
				bestV = abs(v[0]) + abs(v[1]) + abs(v[2]);
				bestP = abs(p[0]) + abs(p[1]) + abs(p[2]);
				bestId = i;
			} else if (abs(v[0]) + abs(v[1]) + abs(v[2]) == bestV) {
				if (abs(p[0]) + abs(p[1]) + abs(p[2]) == bestP) {
					bestP = abs(p[0]) + abs(p[1]) + abs(p[2]);
					bestId = i;
				}
			}
		}

		vals.push_back({p, v, a});
		i++;
	}

	cout << bestId << endl;

	unordered_map<int, vector<int>> p;
	unordered_map<int, vector<int>> v, a;

	for(int i = 0; i < vals.size(); i++) {
		p[i] = vals[i][0];
		v[i] = vals[i][1];
		a[i] = vals[i][2];
	}

	for(int i = 0; i < 1e4; i++) {

		map<vector<int>, vector<int>> posDup;
		for(auto cur : p) {
			posDup[cur.second].push_back(cur.first);
		}

		for(auto cur : posDup) {
			if(cur.second.size() > 1) {
				for(auto val : cur.second) {
					p.erase(val);
				}
			}
		}
		for(auto cur : p) {
			

			v[cur.first][0] += a[cur.first][0];
			v[cur.first][1] += a[cur.first][1];
			v[cur.first][2] += a[cur.first][2];
			p[cur.first][0] += v[cur.first][0];
			p[cur.first][1] += v[cur.first][1];
			p[cur.first][2] += v[cur.first][2];
		}
	}

	cout << p.size() << endl;

	return 0;
}