#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<bool> primes (1e5 + 1, true);
vector<ll> primeList;

void calcPrimes() {
	for(int i = 2; i <= 400; i++) {
		if(primes[i]) {
			primeList.push_back(i);
			int curr = i*i;
			while(curr <= 1e5) {
				primes[curr] = false;
				curr += i;
			}
		}
	}
	for(int i = 401; i <= 1e5; i++) {
		if(primes[i]) {
			primeList.push_back(i);
		}
	}
}

ll prime(ll val) {
	if(primes[val]) return val;
	for(int i : primeList) {
		if(val % i == 0) {
			return i;
		}
	}
}

map<int, int> cnt;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	calcPrimes();
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur;

		while(cur > 1) {
			int curPrime = prime(cur);
			cnt[curPrime]++;
			while(cur % curPrime == 0) {
				cur /= curPrime;
			}
		}
	}

	int best = 1;
	for(auto cur : cnt) {
		best = max(best, cur.second);
	}

	cout << best << endl;
	
	return 0;
}