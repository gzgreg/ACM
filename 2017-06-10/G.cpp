#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	freopen("powersum.in", "r", stdin);
	freopen("powersum.out", "w", stdout);

	int n; cin >> n;
	vector<string> adj;

	for(int i = 0; i < n; i++) {
		string s; cin >> s; adj.push_back(s);
	}

	vector<pii> rowOrder; //arcs out from i
	vector<pii> colOrder; //arcs into i
	for(int i = 0; i < n; i++) {
		int rowSum = 0;
		int colSum = 0;
		for(int j = 0; j < n; j++) {
			rowSum += (adj[i][j] == '1');
			colSum += (adj[j][i] == '1');
		}

		rowOrder.push_back({rowSum, i});
		colOrder.push_back({colSum, i});
	}

	sort(rowOrder.begin(), rowOrder.end());
	sort(colOrder.begin(), colOrder.end());

	for(int i = 1; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(adj[rowOrder[i-1].second][j] == '1' 
				&& adj[rowOrder[i].second][j] == '0') {
				cout << "NO" << endl;
				return 0;
			}

			if(adj[j][colOrder[i-1].second] == '1' 
				&& adj[j][colOrder[i].second] == '0') {
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	vector<int> in(n, 0), out(n, 0);
	for(int i = 0; i < n; i++) {
		out[rowOrder[i].second] = -n + i;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(adj[j][colOrder[i].second] == '1') {
				in[colOrder[i].second] 
					= max(in[colOrder[i].second], -out[j]);
			}
		}
	}

	cout << "YES" << endl;
	for(int i = 0; i < n; i++) {
		cout << out[i] << " " << in[i] << endl;
	}
	cout << 0 << endl;
	
	return 0;
}