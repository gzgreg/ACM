#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int L; cin >> L;
	int Q; cin >> Q;
	vector<string> wordList;
	map<string, set<string>> adj;
	for(int i = 0; i < L; i++) {
		string s; cin >> s;
		for(string b : wordList) {
			if(s.size() != b.size()) continue;
			bool changeFound = false;
			bool valid = false;
			for(int j = 0; j < s.size(); j++) {
				if(s[j] != b[j]) {
					if(changeFound) {
						valid = false;
						break;
					} else {
						changeFound = true;
						valid = true;
					}
				}
			}
			if(valid) {
				adj[s].insert(b);
				adj[b].insert(s);
			}
		}
		wordList.push_back(s);
	}

	for(int i = 0; i < Q; i++) {
		string A, B; cin >> A >> B;

		queue<string> bfsq; bfsq.push(A);
		set<string> visited;
		map<string, int> dist;
		dist[A] = 0;
		while(!bfsq.empty()){
			string curr = bfsq.front(); bfsq.pop();
			for(string s : adj[curr]){
				if(visited.find(s) == visited.end()){
					visited.insert(s);
					bfsq.push(s);
					dist[s] = dist[curr] + 1;
				}
			}
		}
		if(visited.find(B) != visited.end()) {
			cout << dist[B] << endl;
		} else {
			cout << -1 << endl;
		}
	}
	
	return 0;
}