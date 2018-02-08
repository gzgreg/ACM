#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int parent[50001];

int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }
void merge(int x, int y) { parent[find(x)] = find(y);}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, K; cin >> N >> M >> K;
	vector<bool> merged(N);
	set<pair<int, pair<int, int>>> edges;
	for(int i = 0; i < M; i++) {
		int a, b, w; cin >> a >> b >> w;
		edges.insert({w, {a, b}});
	}
	for(int i = 0; i < N; i++) {
		parent[i] = i;
	}

	int numComps = N;
	int ans = 0;
	while(numComps > K) {
		auto cur = *(edges.begin());
		edges.erase(edges.begin());

		if(find(cur.second.first) != find(cur.second.second)) {
				numComps--;
			
			merged[cur.second.first] = true;
			merged[cur.second.second] = true;
			merge(cur.second.first, cur.second.second);
			ans += cur.first;
		}
	}
	cout << ans << endl;
	
	return 0;
}