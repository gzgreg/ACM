#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'
#define INF 1000000000

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;

	while(T--) {
		int N; cin >> N;

		vector<int> deg (N, 0);
		for(int i = 0; i < N-1; i++) {
			int u, v; cin >> u >> v;
			deg[u]++; deg[v]++;
		}

		int price = 0;
		int bestRoot;
		int diff = INF;
		for(int i = 0; i < N; i++) {
			int currPrice = min(500, ((deg[i] - 1) / 2 * 175) + ((deg[i] - 1) % 2) * 100);
			int rootPrice = min(500, (deg[i] / 2 * 175) + (deg[i] % 2) * 100);
			price += currPrice;
			if(rootPrice - currPrice < diff) {
				bestRoot = i;
				diff = rootPrice - currPrice;
			}
		}
		cout << "$" << price + diff << endl;
	}
	
	return 0;
}