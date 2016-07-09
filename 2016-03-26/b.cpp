#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

struct Edge {
	int start, end, id;
	Edge(int start, int end, int id) : start(start), end(end), id(id) {};
	bool operator<(const Edge& rhs) const{
		if(start == rhs.start && end == rhs.end){
			return id < rhs.id;
		}
		else if(start == rhs.start){
			return end < rhs.end;
		} else {
			return start < rhs.start;
		}
	}
};

int cnt = 1;
vector<int> low, pre;
vector<bool> seen;
set<int> bridges;

void dfs(const vector<set<Edge>>& g, int parent, int node){
	pre[node] = cnt++;
	low[node] = pre[node];
	for(Edge a : g[node]){
		if(seen[a.id]) continue;
		seen[a.id] = true;
		if(pre[a.end] == -1){
			dfs(g, a.start, a.end);
			low[node] = min(low[node], low[a.end]);
			if(low[a.end] == pre[a.end]){
				bridges.insert(a.id);
			}
		} else {
			low[node] = min(low[node], pre[a.end]);
		}
	}
}

int main(){
	freopen("bridges.in", "r", stdin);
	freopen("bridges.out", "w", stdout);

	int N, M; scanf("%d", &N); scanf("%d", &M);

	vector<set<Edge>> g;
	for(int i = 0; i < N+1; i++){
		set<Edge> empty;
		g.push_back(empty);
	}
	for(int i = 0; i < M; i++){
		int start, end; scanf("%d", &start); scanf("%d", &end);
		g[start].insert(Edge (start, end, i+1));
		g[end].insert(Edge (end, start, i+1));
	}

	low = vector<int>(N+1, -1);
	pre = vector<int>(N+1, -1);
	seen = vector<bool>(M+1, false);

	dfs(g, 1, 1);
	cout << bridges.size() << endl;
	for(int i : bridges){
		cout << i;
		if(i != *(--bridges.end())) cout << " ";
		else cout << endl;
	}
	return 0;
}