#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> primes;
vector<int> totients (10003, 0);
vector<int> cumsum(10003, 0);

void calcPrimes() {
	primes.push_back(2);
	for(int i = 3; i < 10002; i++) {
		bool isPrime = true;
		for(int j = 0; j < primes.size(); j++) {
			if(i % primes[j] == 0) {
				isPrime = false;
				break;
			}
		}
		if(isPrime) {
			primes.push_back(i);
		}
	}
}

void calcTotients() {
	for(int i = 1; i < 10002; i++) {
		int curr = i;
		for(int j = 0; j < primes.size(); j++) {
			if(primes[j] > curr) break;
			if(i % primes[j] != 0) continue;
			curr = curr * (1 - 1.0/primes[j]) + 0.2 ;
		}
		totients[i] = curr;
		cumsum[i] = cumsum[i-1] + curr;
	}
}

int main(){
	ios::sync_with_stdio(0);
	
	int P; cin >> P;
	calcPrimes();
	calcTotients();
	while(P--) {
		int K, N; cin >> K >> N;

		cout << K << " " << 3 * cumsum[N] - 1 << "/" << 2 << endl;
	}

	return 0;
}