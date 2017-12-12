#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000000007

long long mod_pow(long long base, long long  exp) {
	long long val = 1;
	base = base % MOD;
	
	while(exp > 0) {
		if(exp % 2 == 1) {
			val *= base;
			val %= MOD;
		}
		exp = exp / 2;
		base *= base;
		base %= MOD;
	}
	return val;
}

string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	
	ll ans = 0;
	ll numAs = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'a') {
			numAs++;
		} else {
			if(numAs > 0) {
				ans += mod_pow(2, numAs) - 1;
				ans %= MOD;
			}
		}
	}

	cout << ans << endl;
	
	return 0;
}