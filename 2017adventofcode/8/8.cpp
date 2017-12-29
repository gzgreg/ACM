#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

void execop(map<string, int>& vals, string v, string op, int val) {
	if(op == "inc") {
		vals[v] += val;
	} else {
		vals[v] -= val;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	int ans = -1e9;
	map<string, int> vals;

	while(getline(cin, s)) {
		stringstream str(s);

		string v, op, valstr, junk, cond, condop, condvals;
		int val, condval;

		str >> v >> op >> valstr >> junk >> cond >> condop >> condvals;

		val = stoi(valstr);
		condval = stoi(condvals);

		if(condop == ">") {
			if(vals[cond] > condval) {
				execop(vals, v, op, val);
			}
		} else if (condop == "<") {
			if(vals[cond] < condval) {
				execop(vals, v, op, val);
			}
		} else 	if(condop == ">=") {
			if(vals[cond] >= condval) {
				execop(vals, v, op, val);
			}
		}  else if(condop == "<=") {
			if(vals[cond] <= condval) {
				execop(vals, v, op, val);
			}
		}  else if(condop == "==") {
				if(vals[cond] == condval) {
					execop(vals, v, op, val);
				}
		} else 	if(condop == "!=") {
			if(vals[cond] != condval) {
				execop(vals, v, op, val);
			}
		} 
		for(auto cur : vals) {
			ans = max(ans, cur.second);
		}
	}

	cout << ans << endl;

	return 0;
}