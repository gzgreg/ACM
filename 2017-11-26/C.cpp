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

vector<bool> primes (71, true);
vector<ll> primeList;
map<ll, ll> revPrimes;
vector<bitset<19>> fac(71);

void calcPrimes() {
	for(int i = 2; i < 71; i++) {
		if(primes[i]) {
			primeList.push_back(i);
			revPrimes[i] = primeList.size() - 1;
			int curr = 2*i;
			while(curr <= 70) {
				primes[curr] = false;
				curr += i;
			}
		}
	}
}

ll prime(ll val) {
	if(primes[val]) return -1;
	for(int i : primeList) {
		if(val % i == 0) {
			return i;
		}
	}
}

int memo[71][(1 << 19) + 1];

vector<ll> vals(71);

int dp(int curVal, int bitmask) {
	if(curVal == 71) {
		if(bitmask == 0) return 1;
		return 0;
	} else if (memo[curVal][bitmask] != -1) {
		return memo[curVal][bitmask];
	}

	int oddBitmask = bitmask ^ fac[curVal].to_ulong();
	int evenBitmask = bitmask;
	if(vals[curVal] == 0) {
		return memo[curVal][bitmask] = dp(curVal+1, bitmask);
	}
	ll ans = 0;
	ans += mod_pow(2, vals[curVal] - 1)*dp(curVal + 1, oddBitmask);
	ans %= MOD;
	ans += mod_pow(2, vals[curVal] - 1)*dp(curVal + 1, evenBitmask);
	ans %= MOD;
	return memo[curVal][bitmask] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	calcPrimes();
	for(int i = 2; i <= 70; i++) {
		bitset<19> curFac(0);
		int dividing = i;
		for(auto d : primeList) {
			while(dividing % d == 0) {
				dividing /= d;
				curFac[revPrimes[d]] = !curFac[revPrimes[d]];
			}
		}
		fac[i] = curFac;
	}

	memset(memo, -1, sizeof memo);

	int n; cin >> n;

	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; vals[cur]++;
	}

	cout << (dp(1, 0) - 1 + MOD) % MOD << endl;
	
	return 0;
}