#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;

	vector<set<int>> pos;
	int bestAns = 1e9;
	int bestIdx;
	for(int i = 0; i < m-n+1; i++) {
		set<int> toChange;

		for(int j = 0; j < n; j++) {
			if(s[j] != t[i+j]) {
				toChange.insert(j);
			}
		}

		if(toChange.size() < bestAns) {
			bestAns = toChange.size();
			bestIdx = i;
		}
		pos.push_back(toChange);
	}

	cout << pos[bestIdx].size() << endl;
	for(int i : pos[bestIdx]) {
		cout << i+1 << " ";
	}

	cout << endl;

	return 0;
}