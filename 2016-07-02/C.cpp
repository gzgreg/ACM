#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

set<string> elems = {"h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al", "si", "p", "s", "cl", "ar", "k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr", "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe", "cs", "ba", "la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr", "rf", "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn", "fl", "lv"};

bool dp(string s, int idx, vector<int> memo) {
	if(idx == s.size()) {
		return true;
	}
	if(memo[idx] != -1) {
		if(memo[idx] == 1) return true;
		return false;
	}
	bool ret = false;

	if(idx <= s.size() - 2 && elems.find(s.substr(idx, 2)) != elems.end()) {
		ret = dp(s, idx + 2, memo);
	}

	if(ret){
		memo[idx] = 1;
		return ret;
	} 
	if(elems.find(s.substr(idx, 1)) != elems.end()) {
		ret = dp(s, idx + 1, memo);
	}
	if(ret) {
		memo[idx] = 1;
	} else {
		memo[idx] = 0;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	while(T--) {
		string s; cin >> s;
		vector<bool> memo = vector<bool> (s.size(), false);

		for(int i = 0; i < s.size(); i++) {
			if(i == 0) {
				if(elems.find(s.substr(i, 1)) != elems.end()) {
					memo[i] = true;
				}
			} else if(i == 1) {
				if(memo[0] && elems.find(s.substr(i, 1)) != elems.end()) {
					memo[i] = true;
				}
				if(elems.find(s.substr(i-1, 2)) != elems.end()) {
					memo[i] = true;
				}
			} else {
				if(memo[i-1] && elems.find(s.substr(i, 1)) != elems.end()) {
					memo[i] = true;
				} else if(memo[i-2] && elems.find(s.substr(i-1, 2)) != elems.end()) {
					memo[i] = true;
				}
			}
			
		}
		if(memo[s.size() - 1]) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}