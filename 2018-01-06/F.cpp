#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int parent[1001];

int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }
void merge(int x, int y) { parent[find(x)] = find(y); }

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++) {
		parent[i] = i;
	}

	vector<pair<pair<int, int>, char>> data;
	unordered_map<int, vector<int>> greater, less;

	for(int i = 0; i < m; i++) {
		int a, b; char cmp;
		cin >> a >> cmp >> b;
		a--; b--;
		if(cmp == '>') {
			cmp = '<';
			swap(a, b);
		}
		if(cmp == '=') {
			merge(a, b);
		}
		data.push_back({{a, b}, cmp});
	}
	for(auto cur : data) {
		char cmp = cur.second;
		int a = cur.first.first;
		int b = cur.first.second;
		if(cmp == '<') {
			greater[find(a)].push_back(find(b));
			less[find(b)].push_back(find(a));
		}
	}
	unordered_map<int, int> ans;
	queue<int> known;

	int totSize = 0;
	set<int> seen;
	for(int i = 0; i < n; i++) {
		if(greater[i].size() > 0
			&& less[i].size() > 0) {
			for(auto cur : greater[i]) {
				if(ans[cur] == 0) known.push(cur);
				ans[cur] = 3;
			}
			for(auto cur : less[i]) {
				if(ans[cur] == 0) known.push(cur);
				ans[cur] = 1;
			}
			if(ans[i] == 0) known.push(i);
			ans[i] = 2;
		}
	}
	while(!known.empty()) {
		//if(known.size() % 1000 == 0) cout << known.size() << " " << totSize << endl;
		int val = known.front(); known.pop();
		for(auto cur : greater[val]) {
			if(ans[cur] == 0 && ans[val] == 2) {
				known.push(cur);
				ans[cur] = 3;
			}
		}
		for(auto cur : less[val]) {
			if(ans[cur] == 0 && ans[val] == 2) {
				known.push(cur);
				ans[cur] = 1;
			}
		}
		totSize += greater[val].size() + less[val].size();
	}

	string output = "?BRW";

	for(int i = 0; i < n; i++) {
		cout << output[ans[find(i)]];
	}
	cout << endl;
	
	return 0;
}