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

	vector<int> spacing = {0, 2, 4, 5, 7, 9, 11};
	vector<set<int>> scales (12);
	for(int i = 0; i < 12; i++) {
		for(int j : spacing) {
			scales[i].insert((i + j) % 12);
		}
	}

	map<string, int> t;
	t["A"] = 0;
	t["A#"] = 1;
	t["B"] = 2;
	t["C"] = 3;
	t["C#"] = 4;
	t["D"] = 5;
	t["D#"] = 6;
	t["E"] = 7;
	t["F"] = 8;
	t["F#"] = 9;
	t["G"] = 10;
	t["G#"] = 11;

	map<int, string> trev;
	for(auto cur : t) {
		trev[cur.second] = cur.first;
	}

	int n; cin >> n;
	vector<int> vals;
	for(int i = 0; i < n; i++) {
		string s; cin >> s; vals.push_back(t[s]);
	}
	vector<int> found;
	for(int i = 0; i < 12; i++) {
		bool good = true;
		for(int j : vals) {
			if(!scales[i].count(j)) {
				good = false;
				break;
			}
		}
		if(good) found.push_back(i);
	}

	if(found.size() > 0) {
		for(int i : found) {
			cout << trev[i] << " ";
		}
		cout << endl;
	} else {
		cout << "none" << endl;
	}
	
	return 0;
}