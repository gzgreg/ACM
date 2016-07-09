#include <bits/stdc++.h>

using namespace std;


#define MOD 1000000007

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	long long T; cin >> T;
	while(T--){
		long long m, n, p; cin >> m >> n >> p;
		bool bottom = false;
		long long m2 = m, n2 = n;
		long long ans = 0, temp = 1;
		for(long long i = 0; i < p; i++){
			if(bottom){
				temp *= n2;
				temp %= MOD;
				n2--;
			} else {
				temp *= m2;
				temp %= MOD;
				m2--;
			}
			bottom = !bottom;
		}
		ans += temp;
		temp = 1;
		m2 = m; n2 = n;
		bottom = true;
		for(long long i = 0; i < p; i++){
			if(bottom){
				temp *= n2;
				temp %= MOD;
				n2--;
			} else {
				temp *= m2;
				temp %= MOD;
				m2--;
			}
			bottom = !bottom;
		}
		ans += temp;
		ans %= MOD;
		cout << ans << endl;
	}
	
	return 0;
}