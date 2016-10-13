#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

set<int> primes;

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	for(int i = 2; i < 20100; i++) {
		primes.insert(i);
	}

	for(int i = 2; i < 5000; i++) {
		if(!primes.count(i)) continue;
		for(auto it = primes.find(i); it != primes.end();) {
			int num = *it;
			//cout << num << " " << i << " " << num % i << endl;
			if (num % i == 0 && num != i) {
				//cout << "a";
				it = primes.erase(it);
			} else {
				it++;
			}
		}
	}

	// for(int num : primes) {
	// 	cout << num << " ";
	// }

	while(T--) {
		int m, n; cin >> m >> n;

		if(m == 0) {
			if(n < 0) n = -n;
			if(n % 4 == 3 && primes.count(n)) {
				cout << "P" << endl;
			} else {
				cout << "C" << endl;
			}
			continue;
		}
		if(n == 0) {
			if(m < 0) m = -m;
			if(m % 4 == 3 && primes.count(m)) {
				cout << "P" << endl;
			} else {
				cout << "C" << endl;
			}
			continue;
		}

		int isPrime = primes.count(m*m + n*n);
		if(isPrime) {
			cout << "P" << endl;
		} else {
			cout << "C" << endl;
		}

	}
	
	return 0;
}