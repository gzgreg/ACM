#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	string keyboard[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
	map<char, map<char, int>> dist;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			string str1 = keyboard[i];
			string str2 = keyboard[j];
			for(int k = 0; k < str1.length(); k++) {
				if(!dist.count(str1[k])) {
					dist.insert({str1[k], map<char, int>()});
				}
				for(int l = 0; l < str2.length(); l++) {
					dist[str1[k]].insert({str2[l], abs(i-j) + abs(k-l)});
				}
			}
		}
	}

	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		int l; cin >> l;
		set<pair<int, string>> out;
		while(l--) {
			string curr; cin >> curr;
			int total = 0;
			for(int i = 0; i < s.length(); i++) {
				total += dist[s[i]][curr[i]];
			}
			out.insert({total, curr});
		}

		for(pair<int, string> curr : out) {
			cout << curr.second << " " << curr.first << endl;
		}
	}
	
	return 0;
}