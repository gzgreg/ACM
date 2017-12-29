#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<string, string> par;
map<string, vector<string>> child;
map<string, int> weight;

int dfs(string node) {
	vector<pair<int, int>> weights;
	int totWeight = 0;
	int idx = 0;
	for(auto ch : child[node]) {
		int curWeight = dfs(ch);
		totWeight += curWeight;
		weights.push_back({curWeight, idx++});
	}
	sort(weights.begin(), weights.end());
	if(weights.size() > 1 && weights[0].first != weights[weights.size() - 1].first) {

		cout << node << " ";
		for(int i = 0; i < weights.size(); i++) {
			cout << child[node][weights[i].second] << ":" << weights[i].first << " ";
		}
		cout << endl;
	}
	totWeight += weight[node];
	return totWeight;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	int ans = 0;

	while(getline(cin, s)) {
		stringstream str(s);

		string name; str >> name;
		string w; str >> w;

		string junk;
		if (str >> junk) {
			string ch;
			while(str >> ch) {
				if(ch[ch.size() - 1] == ',') {
					ch = ch.substr(0, ch.size() - 1);
				}
				par[ch] = name;
				child[name].push_back(ch);
			}
		}
		weight[name] = stoi(w.substr(1, w.size() - 2));
	}

	// part 1
	string root;
	for(auto cur : weight) {
		if(!par.count(cur.first)) {
			cout << cur.first << endl;
			root = cur.first;
			break;
		}
	}

	// part 2
	dfs(root);

	return 0;
}