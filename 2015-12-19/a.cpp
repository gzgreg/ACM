#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main(){
	ios::sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m;

	vector<set<int> > adj;
	map<int, int> corr;

	for(int i = 0; i < n; i++){
		set<int> empty;
		adj.push_back(empty);
		corr.insert(make_pair(i, i));
	}

	for(int i = 0; i < m; i++){
		int ai, bi; cin >> ai >> bi;
		adj[ai-1].insert(bi - 1); adj[bi-1].insert(ai - 1);
	}
	vector<pair<int, int> > pairs;

	cin >> k;
	for(int i = 0; i < k; i++){
		int xi, yi; cin >> xi >> yi;
		pairs.push_back(make_pair(xi - 1, yi - 1));
	}

	vector<set<int> > adj2 = adj;
	vector<int> parent (n, -1); parent[0] = -2;

	stack<int> dfs;
	set<int> visit;
	dfs.push(0);
	int cycleNum = n;
	while(!dfs.empty()){
		int curr = dfs.top();
		dfs.pop();
		if(visit.find(curr) != visit.end()) continue;
		for(auto i = adj[curr].begin(); i != adj[curr].end(); i++){
			int conn = *i;
			if(conn == parent[curr]) continue;
			if(visit.find(conn) != visit.end()){
				//cycle found; backtrack
				int back = curr;
				set<int> empty; adj2.push_back(empty);
				//connect placeholder node to replace cycle
				cout << curr << conn;
				while(true){
					if(back == -2) back = conn;
					cout << back;
					corr[back] = cycleNum;
					for(auto it = adj[back].begin(); it != adj[back].end(); it++){
						adj2[cycleNum].insert(*it);
						adj2[*it].erase(back); adj2[*it].insert(cycleNum);
					}
					adj2[back].clear();
					if(back == conn) break;
					back = parent[back];					
				}
				cycleNum++;
				continue;
			}
			parent[conn] = curr;
			dfs.push(conn);
		}
		visit.insert(curr);
	}
	cout << endl;
	for(int i = 0; i < adj2.size(); i++){
		cout << i << " ";
		for(auto it = adj2[i].begin(); it != adj2[i].end(); it++){
			cout << *it << " ";
		}
		cout << endl;
	}
	for(int i = 0; i < n; i++){
		cout << i << " " << corr[i]<< endl;
	}

	for(int i = 0; i < k; i++){
		pair<int, int> curr = pairs[i];
		int start = corr[curr.first];
		int end = corr[curr.second];
		queue<int> bfsq; bfsq.push(start);
		vector<int> nodeVal (cycleNum, -1); nodeVal[start] = start >= n ? 2 : 1;
		set<int> visited;
		while(true){
			int curr = bfsq.front(); bfsq.pop();
			if(curr == end){
				cout << nodeVal[curr] << endl;
				break;
			}
			for(auto it = adj2[curr].begin(); it != adj2[curr].end(); it++){
				if(visited.find(*it) == visited.end()){
					visited.insert(*it);
					bfsq.push(*it);
					nodeVal[*it] = nodeVal[curr] * (*it >= n ? 2 : 1) % MOD;
				}
			}
		}
	}

	return 0;
}