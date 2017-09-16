#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string start = "ABCDEFX";

	set<string> vis;
	vis.insert(start);

	queue<pair<string, int>> bfsq;
	bfsq.push({start, 6});
	map<string, int> dist;
	map<string, string> moves;
	dist[start] = 0;
	moves[start] = "";

	while(!bfsq.empty()) {
		auto cur = bfsq.front(); bfsq.pop();

		if(cur.second == 6) {
			set<int> nextIds = {1, 4};
			for(int i : nextIds) {
				string next = cur.first;
				swap(next[i], next[cur.second]);
				if(!vis.count(next)) {
					vis.insert(next);
					bfsq.push({next, i});
					dist[next] = dist[cur.first] + 1;
					moves[next] = moves[cur.first] + next[cur.second];
				}
				swap(next[i], next[cur.second]);
			}
		} else if(cur.second == 1 || cur.second == 4) {
			set<int> nextIds = {cur.second - 1, cur.second + 1, 6};

			for(int i : nextIds) {
				string next = cur.first;
				swap(next[i], next[cur.second]);
				if(!vis.count(next)) {
					vis.insert(next);
					bfsq.push({next, i});
					dist[next] = dist[cur.first] + 1;
					moves[next] = moves[cur.first] + next[cur.second];
				}
				swap(next[i], next[cur.second]);
			}
		} else {
			set<int> nextIds = {(cur.second + 5) % 6, (cur.second + 1) % 6};
			for(int i : nextIds) {
				string next = cur.first;
				swap(next[i], next[cur.second]);
				if(!vis.count(next)) {
					vis.insert(next);
					bfsq.push({next, i});
					dist[next] = dist[cur.first] + 1;
					moves[next] = moves[cur.first] + next[cur.second];
				}
				swap(next[i], next[cur.second]);
			}
		}
	}

	int P; cin >> P;

	while(P--) {
		int junk; cin >> junk;

		string s; cin >> s; s.push_back('X');
		if(!dist.count(s)) {			
			cout << junk << " NO SOLUTION" << endl;
		} else {
			reverse(moves[s].begin(), moves[s].end());
			cout << junk << " " << dist[s] << " " << moves[s] << endl;
			reverse(moves[s].begin(), moves[s].end());
		}
	}
	
	return 0;
}