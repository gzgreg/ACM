#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<bool> primes (10467398, true);
vector<ll> primeList;

void calcPrimes() {
	for(int i = 2; i <= 4000; i++) {
		if(primes[i]) {
			primeList.push_back(i);
			int curr = i*i;
			while(curr <= 10467397) {
				primes[curr] = false;
				curr += i;
			}
		}
	}
	for(int i = 4001; i <= 10467397; i++) {
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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	calcPrimes();

	int num; cin >> num;

	set<int> divisors;
	for(int i = 0; i < 3; i++) {
		if(num == 1) {
			cout << "NO" << endl;
			return 0;
		}
		int curPrime = prime(num);
		divisors.insert(curPrime);
		num /= curPrime;
	}
	if(num != 1) {
		cout << "NO" << endl;
		return 0;
	}
	if(divisors.size() != 3) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	
	return 0;
}