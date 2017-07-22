#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	
	int c; cin >> c;
	map<string, int> name2ID;
	vector<vector<string>> avail(c, vector<string>(24, ""));
	for(int i = 0; i < c; i++) {
		string name; cin >> name; name2ID[name] = i;
		int ni; cin >> ni;
		for(int j = 0; j < ni; j++) {
			string s, s2; cin >> s >> s2;
			for(int k = 0; k < 24; k++) {
				if(s[k] == '.') {
					avail[i][k] = s2;
				}
			}
		}
	}

	int m; cin >> m;
	for(int i = 0; i < m; i++) {
		int l; cin >> l;
		vector<int> vals;
		for(int j = 0; j < l; j++) {
			string s; cin >> s; vals.push_back(name2ID[s]);
		}
		bool good = false;
		for(int j = 0; j < 24; j++) {
			bool curGood = true;
			set<string> names;
			for(int curr : vals) {
				if(avail[curr][j] != "") {
					names.insert(avail[curr][j]);
				} else {
					curGood = false;
				}
			}
			if(curGood) {
				cout << "Yes ";
				for(string name : names) {
					cout << name << " ";
				}
				cout << endl;
				good = true;
				break;
			}
		}
		if(!good) {
			cout << "No" << endl;
		}
	}

	return 0;
}