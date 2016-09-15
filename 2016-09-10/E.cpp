#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		map<string, set<string>> data;
		map<string, bool> seen;
		map<string, set<string>> backData;
		map<string, bool> backSeen;
		for(int i = 0; i < n; i++) {
			string a; cin >> a;
			int m; cin >> m;
			set<string> strings;
			for(int i = 0; i < m; i++) {
				string curr; cin >> curr; strings.insert(curr);
			}
			cin >> m;
			set<string> local;
			for(int i = 0; i < m; i++) {
				string curr; cin >> curr; local.insert(curr);
			}

			for(string s : strings) {
				if(!seen[s] && data[s].size() == 0) {
					data[s] = local;
				} else {
					seen[s] = true;
					set<string> isect;
					set_intersection(data[s].begin(),data[s].end(),local.begin(),local.end(),inserter(isect, isect.begin()));
					data[s] = isect;
				}
			}
			for(string s : local) {
				if(!backSeen[s] && backData[s].size() == 0) {
					backData[s] = strings;
				} else {
					backSeen[s] = true;
					set<string> isect;
					set_intersection(backData[s].begin(),backData[s].end(),strings.begin(),strings.end(),inserter(isect, isect.begin()));
					backData[s] = isect;
				}
			}
		}
		set<pair<string, string>> out;
		for(pair<string, set<string>> curr : data) {
			for(string s : curr.second) {
				if(backData[s].count(curr.first)) {
					out.insert({curr.first, s});
				}
			}
		}
		for(pair<string, string> curr : out) {
			cout << "(" << curr.first << ", " << curr.second << ")" << endl;
		}
		cout << endl;
	}
	
	return 0;
}