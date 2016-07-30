#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'
#define MOD 1000000009

long long memo[10][10];

long long factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

long long stirling(int n, int k) {
	//number of ways to partition n objects into k nonempty subsets
	if(n == 0 && k == 0) return 1;
	if(n == 0 || k == 0) return 0;
	if(memo[n][k] != -1) return memo[n][k];

	memo[n][k] = k*stirling(n-1, k) + stirling(n-1, k-1);
	return memo[n][k];
}

long long mod_pow(int base, int exp) {
	int val = 1;
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

long long nCr(int n, int k) {
	if(n < k) return 0;
	return factorial[n] / factorial[k] / factorial[n-k];
}

int main(){
	ios::sync_with_stdio(0);

	long long k; cin >> k;
	long long d, m; cin >> d >> m;
	if(m % d != 0) {
		cout << 0 << endl;
		return 0;
	}
	memset(memo, -1, sizeof memo);
	m = m / d;

	long long primeFactors = 0;
	long long limit = sqrt(m)+1;
	// for(int i = 2; i <= limit; i++) {
	// 	if(m % i == 0) {
	// 		while(m % i == 0) {
	// 			m = m/i;
	// 		}

	// 		primeFactors++;
	// 		if(m == 1) break;
	// 	}
	// }
	// if(m != 1) primeFactors++;
	// long long ans = 0;
	// for(long long i = 1; i <= min(primeFactors, k); i++) {
	// 	long long partitions = stirling(primeFactors, i);
	// 	long long numFacs = min(i+1, k);
	// 	//find i ^ k, adding 1 as factor if possible
	// 	//multiply by partitions to get all possibilities with i nontrivial factors
	// 	long long currAns = mod_pow(numFacs, k) * partitions;
	// 	//need to remove cases where some numbers are missing
	// 	int sub = -1;
	// 	for(int j = 1; j < numFacs; j++) {
	// 		currAns += sub * mod_pow(numFacs - j, k) * (i == 1 || i+1 > k ? nCr(numFacs, j) : nCr(numFacs - 1, j));
	// 		if(currAns < 0) currAns += MOD;
	// 		sub *= -1;
	// 	}
	// 	ans += currAns;
	// 	ans %= MOD;
	// }
	long long factorCount = 0;
	for(int i = 2; i <= limit; i++) {
		if(m % i == 0) {
			int j = 0;
			while(m % i == 0) {
				m = m/i;
				factorCount++;
				j++;
			}
			factorCount++;
			primeFactors++;
			if(m == 1) break;
		}
	}
	if(m != 1){
		primeFactors++;
		factorCount++;
	}
	long long ans = mod_pow(factorCount, k);
	cout << ans << endl;
	long long sub = -1;
	for(long long i = 1; i <= 2*primeFactors; i++) {
		ans += sub * mod_pow(factorCount - i, k) * nCr(2*primeFactors, i);
		cout << ans << endl;
		sub *= -1;
	}

	cout << ans << endl;

	return 0;
}