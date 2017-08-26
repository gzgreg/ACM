#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<bool> primes (5e6+1, true);
vector<ll> primeList;

void calcPrimes() {
	for(int i = 2; i < 3000; i++) {
		if(primes[i]) {
			primeList.push_back(i);
			int curr = i*i;
			while(curr <= 5000000) {
				primes[curr] = false;
				curr += i;
			}
		}
	}
	for(int i = 3000; i <= 5e6; i++) {
		if(primes[i]) {
			primeList.push_back(i);
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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T; cin >> T;
	while(T--) {
		int N; cin >> N;
		if(N == 1) {
			cout << "first" << endl;
		} else if (N == 2 || N == 3) {
			cout << "second" << endl;
		} else {
			cout << "first" << endl;
		}
	}

	return 0;
}