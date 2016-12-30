#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	map<int, pair<pair<bool, int>, pair<bool, int>>> graph;

	map<int, set<int>> nums;

	map<int, int> out;

	string s;
	while(getline(cin, s)) {
		if(s[0] == 'v') {
			string val;
			int i = 6;
			for(; s[i] != ' '; i++) {
				val.push_back(s[i]);
			}
			int valInt = atoi(val.c_str());
			i += 13;
			val  = "";
			for(; i < s.size(); i++) {
				val.push_back(s[i]);
			}
			int botNum = atoi(val.c_str());
			nums[botNum].insert(valInt);
		} else {
			string val;
			int i = 4;
			for(; s[i] != ' '; i++) {
				val.push_back(s[i]);
			}
			int botNum = atoi(val.c_str());
			i += 14;
			bool isOut1 = s[i] == 'o';
			i += isOut1 ? 7 : 4;
			val = "";
			for(; s[i] != ' '; i++) {
				val.push_back(s[i]);
			}
			int out1 = atoi(val.c_str());

			i += 13;
			bool isOut2 = s[i] == 'o';
			i += isOut2 ? 7 : 4;
			val = "";
			for(; i < s.size(); i++) {
				val.push_back(s[i]);
			}
			int out2 = atoi(val.c_str());
			graph.insert({botNum, {{isOut1, out1}, {isOut2, out2}}});
		}
	}

	set<int> visited;

	while(1) {
		bool changed = false;
		for(pair<int, pair<pair<bool, int>, pair<bool, int>>> curr : graph) {
			if(visited.count(curr.first)) continue;
			// if(nums[curr.first].count(61) && nums[curr.first].count(17)) {
			// 	cout << curr.first;
			// 	return 0;
			// }
			if(nums[curr.first].size() < 2) continue;
			visited.insert(curr.first);
			changed = true;
			if(!curr.second.first.first) {
				if(!nums[curr.second.first.second].count(*(nums[curr.first].begin()))){
					nums[curr.second.first.second].insert(*(nums[curr.first].begin()));
				}
			} else {
				out[curr.second.first.second] = *(nums[curr.first].begin());
			}

			if(!curr.second.second.first) {
				if(!nums[curr.second.second.second].count(*(++(nums[curr.first].begin())))){
					nums[curr.second.second.second].insert(*(++(nums[curr.first].begin())));
				}
			} else {
				out[curr.second.second.second] = *(++nums[curr.first].begin());
			}
		}
		if(!changed) {
			for(pair<int, set<int>> curr : nums) {
				cout << curr.first << " ";
				for(int i : curr.second) {
					cout << i << " ";
				}
				cout << endl << flush;
			}
			break;
		}
	}

	for(int i = 0; i < 21; i++) {
		cout << i << " " <<  out[i] << endl;
	}

	cout << out[0] * out[1] * out[2] << endl;
	
	return 0;
}