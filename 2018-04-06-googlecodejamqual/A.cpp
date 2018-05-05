#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll damage(string& prog) {
	ll totDamage = 0;
	ll curDamage = 1;
	for(char cur : prog) {
		if(cur == 'C') curDamage *= 2;
		else totDamage += curDamage;
	}
	return totDamage;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	for(int id = 1; id <= T; id++) {
		cout << "Case #" << id << ": ";

		ll D; string P;
		cin >> D >> P;
		int ans = 0;
		while(damage(P) > D) {
			bool change = false;
			for(int i = P.size() - 1; i > 0; i--) {
				if(P[i] == 'S' && P[i-1] == 'C') {
					swap(P[i], P[i-1]);
					change = true;
					break;
				}
			}
			if(!change) {
				ans = 1e9;
				break;
			}
			ans++;
		}
		if(ans == 1e9) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << ans << endl;
		}
	}
	
	return 0;
}