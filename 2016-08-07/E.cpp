#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int n, m, s, t; cin >> n >> m >> s >> t;
	vector<set<int>> adj (n, set<int>());
	vector<ll> numSquawk (n, 0);

	for(int i = 0; i < m; i++) {
		int first, second; cin >> first >> second;
		adj[first].insert(second);
		adj[second].insert(first);
	}

	numSquawk[s] = 1;
	for(int i = 0; i < t; i++) {
		vector<ll> newNumSquawk (n, 0);
		for(int j = 0; j < n; j++) {
			if(numSquawk[j] == 0) continue;
			for(int conn : adj[j]) {
				newNumSquawk[conn] += numSquawk[j];
			}
		}
		numSquawk = newNumSquawk;
	}

	ll total = 0;
	for(int i = 0; i < n; i++) {
		total += numSquawk[i];
	}

	cout << total << endl;
	
	return 0;
}