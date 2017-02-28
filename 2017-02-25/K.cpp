#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<set<int>> classes;
vector<set<int>> tree;
vector<set<vector<int>>> players;
vector<set<int>> skills;

bool cmp(int i, int j) {
	return classes[i].size() > classes[j].size();
}

void dfs(int node) {
	set<int> complete;
	for(int child : tree[node]) {
		if(child == node) continue;
		dfs(child);
		for(int i : classes[child]) {
			complete.insert(i);
		}
	}
	if(complete.size() != classes[node].size() && node != 0) return;
	if(tree[node].size() == 0) return;
	while(true) {
		vector<int> newSet;
		bool empty = false;
		for(int child : tree[node]) {
			if(child == node) continue;
			if(!players[child].empty()) {
				const vector<int> elems = *(players[child].begin());
				for(int elem : elems) {
					newSet.push_back(elem);
				}
				players[child].erase(elems);
			} else {
				empty = true;
				break;
			}
		}
		if(empty) break;
		players[node].insert(newSet);
	}
}

int main(){
	ios::sync_with_stdio(0);

	int n, m, p; cin >> n >> m >> p;

	classes.push_back({});
	skills = vector<set<int>> (n, set<int>());
	for(int i = 0; i < m; i++) {
		int Si; cin >> Si;
		set<int> currSkills;
		for(int j = 0; j < Si; j++) {
			int curr; cin >> curr; currSkills.insert(curr-1);
			skills[curr-1].insert(i+1);
		}
		classes.push_back(currSkills);
	}

	players = vector<set<vector<int>>> (m+1, set<vector<int>>());
	for(int i = 0; i < p; i++) {
		int player; cin >> player;
		players[player].insert({i + 1});
	}

	tree = vector<set<int>> (m+1, set<int>());
	vector<int> par(m+1, 0);
	for(set<int> skill : skills) {
		vector<int> ordered;
		for(int i : skill) {
			ordered.push_back(i);
		}
		sort(ordered.begin(), ordered.end(), cmp);
		for(int i = 1; i < ordered.size(); i++) {
			par[ordered[i]] = ordered[i-1];
		}
	}

	for(int i = 0; i < m+1; i++) {
		tree[par[i]].insert(i);
	}

	dfs(0);
	cout << players[0].size() << endl;
	for(vector<int> ans : players[0]) {
		cout << ans.size() << " ";
		for(int curr : ans) {
			cout << curr << " ";
		}
		cout << endl;
	}

	return 0;
}