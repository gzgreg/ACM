#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	string s = "fbgdceah";

	string r;
	stack<vector<string>> rules;

	while(cin >> r) {
		vector<string> currRule;
		if(r == "swap") {
			currRule.push_back(r);
			cin >> r;
			currRule.push_back(r);
			if(r == "position") {
				cin >> r; currRule.push_back(r);
				cin >> r; cin >> r; cin >> r;
				currRule.push_back(r);
			} else {
				cin >> r;
				char pos1, pos2; currRule.push_back(r);
				cin >> r; cin >> r; cin >> r;
				currRule.push_back(r);
			}
		} else if (r == "rotate") {
			currRule.push_back(r);
			string dir; cin >> dir;
			if(dir == "based") {
				currRule.push_back(dir);
				cin >> dir >> dir >> dir >> dir >> dir;
				
				currRule.push_back(dir);
			} else {
				currRule.push_back(dir);
				cin >> r;
				int rot = atoi(r.c_str());
				if(dir == "right") rot = -rot;
				char a[33]; sprintf(a, "%d", rot);
				currRule.push_back(string(a));
				cin >> r;
			}
			
		} else if (r == "reverse") {
			currRule.push_back(r);
			cin >> r; cin >> r;
			int pos1, pos2; currRule.push_back(r);
			cin >> r; cin >> r;
			currRule.push_back(r);
		} else {
			currRule.push_back(r);
			cin >> r; cin >> r;
			int pos1, pos2; currRule.push_back(r);
			cin >> r; cin >> r; cin >> r;
			currRule.push_back(r);
		}
		rules.push(currRule);
	}

	while(!rules.empty()) {
		vector<string> curr = rules.top(); rules.pop();
		for(int i = 0; i < curr.size(); i++) {
			cout << curr[i] << " ";
		}
		cout << endl;
		if(curr[0] == "swap") {
			if(curr[1] == "position") {
				int pos1, pos2;
				pos1 = atoi(curr[2].c_str());
				pos2 = atoi(curr[3].c_str());

				char tmp = s[pos1];
				s[pos1] = s[pos2];
				s[pos2] = tmp;
			} else {
				char pos1, pos2; pos1 = curr[2][0];
				pos2 = curr[3][0];

				for(int i = 0; i < s.size(); i++) {
					if(s[i] == pos1) {
						s[i] = pos2;
					} else if (s[i] == pos2) {
						s[i] = pos1;
					}
				}
			}
		} else if (curr[0] == "rotate") {
			if(curr[1] == "based") {
				char letter = curr[2][0];
				string tmp;
				for(int i = 0; i < s.size(); i++) {
					tmp = "";
					for(int j = 0; j < s.size(); j++) {
						tmp.push_back(s[(i + j + (int) 2*s.size()) % s.size()]);
					}
					int rot;
					for(int i = 0; i < s.size(); i++) {
						if(tmp[i] == letter) {
							rot = i + 1 + (i >= 4 ? 1 : 0);
							break;
						}
					}
					rot += (int) 2*s.size();
					rot %= s.size();
					if(rot == i) {
						break;
					}
				}
				s = tmp;
			} else {
				int rot = atoi(curr[2].c_str());
				rot = -rot;
				string tmp;
				for(int i = 0; i < s.size(); i++) {
					tmp.push_back(s[(i + rot + (int)2*s.size()) % s.size()]);
				}
				s = tmp;
			}
		} else if (curr[0] == "reverse") {
			int pos1, pos2; pos1 = atoi(curr[1].c_str());
			pos2 = atoi(curr[2].c_str());

			reverse(s.begin() + pos1, s.begin() + pos2 + 1);
		} else {
			int pos1, pos2; pos1 = atoi(curr[2].c_str());
			pos2 = atoi(curr[1].c_str());

			string tmp; tmp.push_back(s[pos1]);
			s.erase(pos1, 1);
			s.insert(pos2, tmp);
		}
		cout << s << endl;
	}

	cout << s << endl;
	
	return 0;
}