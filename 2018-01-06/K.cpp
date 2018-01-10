#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

unordered_map<string, int> hashes;
unordered_map<int, string> revHashes;
set<int> eq;
map<vector<int>, int> repl;

void generateHashes() {
	int idx = 0;
	vector<string> hex = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", 
							"A", "B", "C", "D", "E", "F"};
	for(int i = 1; i <= 8; i++) {
		for(int j = 1; j <= 8; j++) {
			std::ostringstream ss;
			ss << "MOV R";
			ss << i;
			ss << ", R";
			ss << j;
			hashes[ss.str()] = idx;
			if(i == j) eq.insert(idx);
			idx++;
		}
	}

	for(int i = 1; i <= 8; i++) {
		for(auto c1 : hex) {
			for(auto c2 : hex) {
				std::ostringstream ss;
				ss << "MOV R";
				ss << i;
				ss << ", ";
				ss << c1 << c2;
				hashes[ss.str()] = idx;
				if(c1 == c2 && c1 == "0") eq.insert(idx);
				idx++;
			}		
		}
	}

	for(int i = 1; i <= 8; i++) {
		for(int j = 1; j <= 8; j++) {
			std::ostringstream ss;
			ss << "ADD R";
			ss << i;
			ss << ", R";
			ss << j;
			hashes[ss.str()] = idx;
			if(i == j) eq.insert(idx);
			idx++;
		}
	}

	for(int i = 1; i <= 8; i++) {
		for(auto c1 : hex) {
			for(auto c2 : hex) {
				std::ostringstream ss;
				ss << "ADD R";
				ss << i;
				ss << ", ";
				ss << c1 << c2;
				hashes[ss.str()] = idx;
				idx++;
			}		
		}
	}

	for(int i = 1; i <= 8; i++) {
		for(int j = 1; j <= 8; j++) {
			std::ostringstream ss;
			ss << "XOR R";
			ss << i;
			ss << ", R";
			ss << j;
			hashes[ss.str()] = idx;
			if(i == j) eq.insert(idx);
			idx++;
		}
	}

	for(int i = 1; i <= 8; i++) {
		for(auto c1 : hex) {
			for(auto c2 : hex) {
				std::ostringstream ss;
				ss << "XOR R";
				ss << i;
				ss << ", ";
				ss << c1 << c2;
				hashes[ss.str()] = idx;
				if(c1 == c2 && c1 == "0") eq.insert(idx);
				idx++;
			}		
		}
	}

	for(int i = 1; i <= 8; i++) {
		std::ostringstream ss;
		ss << "PUSH R";
		ss << i;
		hashes[ss.str()] = idx;
		idx++;
	}
	for(int i = 1; i <= 8; i++) {
		std::ostringstream ss;
		ss << "POP R";
		ss << i;
		hashes[ss.str()] = idx;
		idx++;
	}

	// for(auto cur : hashes) {
	// 	revHashes[cur.second] = cur.first;
	// }
	////////////////////////////////////////////////////////
	idx = 0;
	for(int i = 1; i <= 8; i++) {
		for(int j = 1; j <= 8; j++) {
			vector<int> match;
			std::ostringstream ss;
			ss << "PUSH R";
			ss << j;
			match.push_back(hashes[ss.str()]);
			ss.str("");
			ss << "POP R";
			ss << i;
			match.push_back(hashes[ss.str()]);
			repl[match] = idx;
			idx++;
		}
	}

	for(int i = 1; i <= 8; i++) {
		for(auto c1 : hex) {
			for(auto c2 : hex) {
				vector<int> match;
				std::ostringstream ss;
				ss << "XOR R";
				ss << i;
				ss << ", R";
				ss << i;
				match.push_back(hashes[ss.str()]);
				ss.str("");
				ss << "ADD R" << i;
				ss << ", " << c1 << c2;
				match.push_back(hashes[ss.str()]);
				repl[match] = idx;
				idx++;
			}		
		}
	}

	for(int x = 1; x <= 8; x++) {
		for(int y = 1; y <= 8; y++) {
			for(int z = 1; z <= 8; z++) {
				if(z == x) continue;

				vector<int> match;
				std::ostringstream ss;
				ss << "PUSH R" << z;
				match.push_back(hashes[ss.str()]);
				ss.str("");
				ss << "MOV R" << z << ", R" << y;
				match.push_back(hashes[ss.str()]);
				ss.str("");
				ss << "ADD R" << x << ", R" << z;
				match.push_back(hashes[ss.str()]);
				ss.str("");
				ss << "POP R" << z;
				match.push_back(hashes[ss.str()]);
				repl[match] = idx;
			}
			idx++;
		}
	}

	for(int x = 1; x <= 8; x++) {
		for(auto c1 : hex) {
			for(auto c2 : hex) {
				for(int z = 1; z <= 8; z++) {
					if(z == x) continue;
					vector<int> match;
					std::ostringstream ss;
					ss << "PUSH R" << z;
					match.push_back(hashes[ss.str()]);
					ss.str("");
					ss << "MOV R" << z << ", " << c1 << c2;
					match.push_back(hashes[ss.str()]);
					ss.str("");
					ss << "ADD R" << z << ", R" << x;
					match.push_back(hashes[ss.str()]);
					ss.str("");
					ss << "MOV R" << x << ", R" << z;
					match.push_back(hashes[ss.str()]);
					ss.str("");
					ss << "POP R" << z;
					match.push_back(hashes[ss.str()]);
					repl[match] = idx;
				}
				idx++;
			}		
		}
	}

	for(int x = 1; x <= 8; x++) {
		for(int y = 1; y <= 8; y++) {
			for(int z = 1; z <= 8; z++) {
				if(z == x) continue;
				for(auto c1 : hex) {
					for(auto c2 : hex) {
						if(c1 == "0" && c2 == "0"){
							continue;
						} 
						vector<int> match;

						std::ostringstream ss;
						ss << "PUSH R" << z;
						match.push_back(hashes[ss.str()]);
						ss.str("");
						ss << "MOV R" << z << ", R" << y;
						match.push_back(hashes[ss.str()]);
						ss.str("");
						ss << "XOR R" << z << ", " << c1 << c2;
						match.push_back(hashes[ss.str()]);
						ss.str("");
						ss << "XOR R" << x << ", R" << z;
						match.push_back(hashes[ss.str()]);
						ss.str("");
						ss << "MOV R" << z << ", " << c1 << c2;
						match.push_back(hashes[ss.str()]);
						ss.str("");
						ss << "XOR R" << x << ", R" << z;
						match.push_back(hashes[ss.str()]);
						ss.str("");
						ss << "POP R" << z;
						match.push_back(hashes[ss.str()]);
						repl[match] = idx;
					}
				}
			}
			idx++;
		}
	}

	for(int x = 1; x <= 8; x++) {
		for(auto c1 : hex) {
			for(auto c2 : hex) {
				for(int z = 1; z <= 8; z++) {
					if(z == x) continue;
					vector<int> match;

					std::ostringstream ss;
					ss << "PUSH R" << z;
					match.push_back(hashes[ss.str()]);
					ss.str("");
					ss << "XOR R" << z << ", " << c1 << c2;
					match.push_back(hashes[ss.str()]);
					ss.str("");
					ss << "XOR R" << x << ", R" << z;
					match.push_back(hashes[ss.str()]);
					ss.str("");
					ss << "POP R" << z;
					match.push_back(hashes[ss.str()]);
					ss.str("");
					ss << "XOR R" << x << ", R" << z;
					match.push_back(hashes[ss.str()]);
					repl[match] = idx;
				}
				idx++;
			}		
		}
	}

	for(int x = 1; x <= 8; x++) {
		for(int z = 1; z <= 8; z++) {
			if(x == z) continue;
			vector<int> match;
			std::ostringstream ss;
			ss << "PUSH R" << x;
			match.push_back(hashes[ss.str()]);
			ss.str("");
			ss << "MOV R" << x << ", R" << z;
			match.push_back(hashes[ss.str()]);
			ss.str("");
			ss << "POP R" << z;
			match.push_back(hashes[ss.str()]);
			ss.str("");
			ss << "PUSH R" << z;
			match.push_back(hashes[ss.str()]);
			ss.str("");
			ss << "XOR R" << x << ", R" << z;
			match.push_back(hashes[ss.str()]);
			ss.str("");
			ss << "XOR R" << z << ", R" << x;
			match.push_back(hashes[ss.str()]);
			ss.str("");
			ss << "XOR R" << x << ", R" << z;
			match.push_back(hashes[ss.str()]);
			repl[match] = idx;
		}
		idx++;
	}
	for(int x = 1; x <= 8; x++) {
		for(int z = 1; z <= 8; z++) {
			if(x == z) continue;
			vector<int> match;
			std::ostringstream ss;
			ss << "MOV R" << x << ", R" << z;
			match.push_back(hashes[ss.str()]);
			ss.str("");
			ss << "POP R" << z;
			match.push_back(hashes[ss.str()]);
			ss.str("");
			ss << "XOR R" << x << ", R" << z;
			match.push_back(hashes[ss.str()]);
			ss.str("");
			ss << "XOR R" << z << ", R" << x;
			match.push_back(hashes[ss.str()]);
			ss.str("");
			ss << "XOR R" << x << ", R" << z;
			match.push_back(hashes[ss.str()]);
			repl[match] = idx;
		}
		idx++;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	generateHashes();
	int n; cin >> n;
	string junk; getline(cin, junk);
	set<pair<int, int>> input;
	for(int i = 0; i < n; i++) {
		string cur;
		getline(cin, cur);
		//cout << i << " " << hashes[cur] << endl;
		input.insert({i, hashes[cur]});
	}

	for(int i = 0; i < (int) input.size(); i++) {
		auto cur = input.lower_bound({i, 0});
		i = cur->first;
		auto it = cur;
		vector<int> curRepl;
		for(int j = 0; j < 7; j++) {
			curRepl.push_back(cur->second);
			cur++;
			if(repl.count(curRepl)) {
				input.erase(it, cur);		
				input.insert({i, repl[curRepl]});
				// for(auto val : input) {
				// 	cout << revHashes[val.second] << endl;
				// }
				// cout << "==============" << endl;
				i-=8;
				//cout << i << endl;
				break;
			}

			if(cur == input.end()) break;
		}
		//cout << i << endl;
	}
	cout << input.size() << endl;
	for(auto val : input) {
		for(auto cur : hashes) {
			if(cur.second == val.second) {
				cout << cur.first << endl;
				break;
			}
		}
	}
	return 0;
}