#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'
#define MOD 1000000007

long long mod_pow(long long base, long long  exp) {
	long long  val = 1;
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

int main(){
	ios::sync_with_stdio(0);

	int N; cin >> N;
	vector<long long> nums;
	for(int i = 0; i < N; i++) {
		long long k; cin >> k; nums.push_back(k);
	}
	long long ans = 1;
	long long prevNum = 1;
	long long cumsum = 1;
	for(int i = 1; i < N; i++) {
		int currNum = nums[i];

		ans *= mod_pow((mod_pow(2, cumsum + currNum - 1) % MOD) * (mod_pow(2, prevNum) - 1), currNum);
		ans %= MOD;
		cumsum += currNum;
		cumsum %= MOD;
		prevNum = currNum;
	}

	cout << ans << endl;
	
	return 0;
}