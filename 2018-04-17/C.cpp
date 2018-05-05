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

	int n, U; cin >> n >> U;

	vector<int> energies;
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; energies.push_back(cur);
	}
	int k = 2;
	ld bestAns = -0.1;
	for(int i = 0; i < n-2; i++) {
		int j = i+1;
		//cout << i << " " << j << " " << k << endl;
		while(k+1 < n && energies[k+1] <= energies[i] + U) {
			k++;
		}
		if(k <= j || energies[k] > energies[i] + U) continue;

		bestAns = max(bestAns, ((ld)energies[k] - energies[j]) / (energies[k] - energies[i]));
	}
	if(bestAns < 0.0) cout << -1 << endl;
	else cout << fixed << setprecision(10) << bestAns << endl;
	return 0;
}