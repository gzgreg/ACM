#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	string s; cin >> s >> s >> s >> s >> s >> s >> s >> s;

	map<pii, vector<int>> nodes;

	while(cin >> s) {
		int i = 16;
		int xInt, yInt;
		string x;

		while(s[i] >= '0' && s[i] <= '9') {
			x.push_back(s[i]);
			i++;
		}
		xInt = atoi(x.c_str());
		x = "";
		i += 2;
		while(s[i] >= '0' && s[i] <= '9') {
			x.push_back(s[i]);
			i++;
		}
		yInt = atoi(x.c_str());

		cin >> s;

		int size = atoi(s.substr(0, s.size() - 1).c_str());

		cin >> s;
		int used = atoi(s.substr(0, s.size() - 1).c_str());

		cin >> s;
		int av = atoi(s.substr(0, s.size() - 1).c_str());

		cin >> s;
		int pct = atoi(s.substr(0, s.size() - 1).c_str());

		nodes[{xInt, yInt}] = {size, used, av, pct};
	}
	int numPairs = 0;

	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 32; j++) {
			pii node1 = {i, j};
			for(int k = 0; k < 32; k++) {
				for(int l = 0; l < 32; l++) {
					pii node2 = {k, l};

					if(node1 == node2) continue;
					if(!nodes.count(node1) || !nodes.count(node2)) continue;

					if(nodes[node1][1] == 0) continue;
					if(nodes[node1][1] <= nodes[node2][2]){
						numPairs++;
						cout << node1.first << " " << node1.second << " " << node2.first << " " << node2.second << endl;
					}
				}
			}
		}
	}

	cout << numPairs << endl;
	
	return 0;
}