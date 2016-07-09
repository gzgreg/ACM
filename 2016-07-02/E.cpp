#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'
map<string, string> finished;
map<string, pair<string, string>> partial;
map<string, vector<int>> memo;
string word;

int dp(string s, int j) {
	if(memo.find(s) != memo.end()) {
		if(memo[s][j] != -1) {
			return memo[s][j];
		}
	} else {
		memo[s] = vector<int> (2001, -1);
	}
	if(finished.find(s) != finished.end()) {
		string curr = finished[s];
		int oldJ = j;
		for(int i = 0; i < curr.size(); i++) {
			if(curr[i] == word[j]) {
				j++;
			}
		}
		memo[s][oldJ] = j;
		return j;
	} else {
		pair<string, string> toGet = partial[s];
		memo[s][j] = dp(toGet.second, dp(toGet.first, j));
		return memo[s][j];
	}
}

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	while(T--) {
		memo = map<string, vector<int>> ();
		int k; cin >> k;
		for(int i = 0; i < k; i++) {
			string key; cin >> key;
			string ignore; cin >> ignore;
			string curr; cin >> curr;
			if(islower(curr[0])) {
				finished.insert({key, curr});
			} else {
				string curr2; cin >> ignore >> curr2;
				partial.insert({key, {curr, curr2}});
			}
		}
		string s; cin >> s;
		cin >> word;
		int j = dp(s, 0);
		if(j == word.size()) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		finished.clear();
		partial.clear();
		continue;
	}
	
	return 0;
}