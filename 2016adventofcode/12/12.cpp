#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	
	vector<vector<int>> instrs;

	vector<int> regs (4, 0);
	regs[2] = 1;
	string s;
	while(cin >> s) {
		vector<int> instr;
		if(s[0] == 'c') {
			instr.push_back(0);
			string start, dest; cin >> start >> dest;

			if(start[0] == 'a'
				|| start[0] == 'b'
				|| start[0] == 'c'
				|| start[0] == 'd') {
				instr.push_back(1);
				instr.push_back(start[0] - 'a');
			} else {
				instr.push_back(0);
				instr.push_back(atoi(start.c_str()));
				
			}
			instr.push_back(dest[0] - 'a');
		} else if (s[0] == 'i') {
			instr.push_back(1);
			string curr; cin >> curr; instr.push_back(curr[0] - 'a');
		} else if (s[0] == 'd') {
			instr.push_back(2);
			string curr; cin >> curr; instr.push_back(curr[0] - 'a');
		} else {
			instr.push_back(3);
			string start, dest; cin >> start >> dest;
			if(start[0] == 'a'
				|| start[0] == 'b'
				|| start[0] == 'c'
				|| start[0] == 'd') {
				instr.push_back(1);
				instr.push_back(start[0] - 'a');
			} else {
				instr.push_back(0);
				
				instr.push_back(atoi(start.c_str()));
			}
			instr.push_back(atoi(dest.c_str()));

		}
		instrs.push_back(instr);
	}
	int i = 0;
	while(i < instrs.size()) {
		vector<int> instr = instrs[i];
		switch(instr[0]) {
			case 0:
				if(instr[1]) {
					regs[instr[3]] = regs[instr[2]];
				} else {
					regs[instr[3]] = instr[2];
				}
				break;
			case 1:
				regs[instr[1]]++;
				break;
			case 2:
				regs[instr[1]]--;
				break;
			case 3:
				if(instr[1]) {
					if(regs[instr[2]]) {
						i += instr[3] - 1;
					}
				} else {
					if(instr[2]) {
						i += instr[3] - 1;
					}
				}
				break;
		}
		i++;
	}
	cout << regs[0] << endl;
	
	return 0;
}