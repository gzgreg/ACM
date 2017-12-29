#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pair<string, pair<pair<ll, bool>, pair<ll, bool>>>> instr;

vector<ll> idx(2);
vector<queue<ll>> comm(2);
vector<map<char, ll>> regs(2);
vector<ll> sends(2);

ll getVal(int i, ll val, bool isReg) {
	if(isReg) {
		return regs[i][val];
	} else {
		return val;
	}
}


void runProg(int i) {
	while(idx[i] >= 0 && idx[i] < instr.size()) {
		auto curInstr = instr[idx[i]];
		string ask = curInstr.first; 
		char reg = curInstr.second.first.first;
		bool isRegReg = curInstr.second.first.second;
		ll val = curInstr.second.second.first;
		bool isReg = curInstr.second.second.second;
		if(ask == "snd") {
			sends[i]++;
			comm[!i].push(getVal(i, reg, isRegReg));
		} else if (ask == "set") {
			regs[i][reg] = getVal(i, val, isReg);
		} else if (ask == "add") {
			regs[i][reg] += getVal(i, val, isReg);
		} else if (ask == "mul") {
			regs[i][reg] *= getVal(i, val, isReg);
		} else if (ask == "mod") {
			regs[i][reg] %= getVal(i, val, isReg);
		} else if (ask == "rcv") {
			if(comm[i].empty()) break;
			regs[i][reg] = comm[i].front(); comm[i].pop();
		} else if (ask == "jgz") {
			if(getVal(i, reg, isRegReg) > 0) {
				idx[i] += getVal(i, val, isReg) - 1;
			}
		}
		idx[i]++;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	while(getline(cin, s)) {
		stringstream str(s);

		string ask; string reg; string val = "0";
		str >> ask >> reg;
		pair<ll, bool> regVal;

		if(reg[0] >= 'a' && reg[0] <= 'z') {
			regVal = {reg[0], true};
		} else {
			regVal = {stoi(reg), false};
		}

		if(ask == "set"
			|| ask == "add"
			|| ask == "mul"
			|| ask == "mod"
			|| ask == "jgz") {
			str >> val;
			if(val[0] >= 'a' && val[0] <= 'z') {
				instr.push_back({ask, {regVal, {val[0], true}}});
			} else {
				instr.push_back({ask, {regVal, {stoi(val), false}}});
			}
		} else {
			instr.push_back({ask, {regVal, {stoi(val), false}}});
		}
	}

	regs[0]['p'] = 0;
	regs[1]['p'] = 1;
	do {
		runProg(0);
		runProg(1);
	} while(!comm[0].empty() || !comm[1].empty());
	cout << sends[1] << endl;

	return 0;
}