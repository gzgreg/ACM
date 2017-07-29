#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	
	string s; cin >> s;
	map<char, bool> goodId;
	for(char i : s) {
		goodId[i] = true;
	}

	string pat; cin >> pat;

	int n; cin >> n;

	for(int i = 0; i < n; i++) {
		string cur; cin >> cur;
		int curId = 0;
		bool good = true;
		for(int i = 0; i < pat.size(); i++) {
			if(curId >= cur.size()) {
				if(i != pat.size() - 1 || pat[i] != '*') good = false;
				break;
			}
			if(pat[i] == '?') {
				if(!goodId[cur[curId]]) {
					good = false;
					break;
				} else {
					curId++;
				}
			} else if (pat[i] == '*') {
				while(!goodId[cur[curId]] && curId < cur.size() - (pat.size() - i-1)) {
					curId++;
				}
			} else {
				if(pat[i] != cur[curId]) {
					good = false;
					break;
				} else {
					curId++;
				}
			}
		}
		if(curId != cur.size()) {
			good = false;
		}
		cout << (good ? "YES" : "NO") << endl;
	}

	return 0;
}