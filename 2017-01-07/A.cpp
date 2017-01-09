#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	stack<int> reqs;
	int n, m; cin >> n >> m;

	for(int i = 0; i < m; i++) {
		int curr; cin >> curr; reqs.push(curr);
	}

	set<int> visited;

	while(!reqs.empty()) {
		int curr = reqs.top(); reqs.pop();
		if(!visited.count(curr)) {
			cout << curr << endl;
			visited.insert(curr);
		}
	}

	for(int i = 1; i <= n; i++) {
		if(!visited.count(i)) {
			cout << i << endl;
		}
	}
	
	return 0;
}