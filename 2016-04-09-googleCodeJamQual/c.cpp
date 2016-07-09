#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pii;
typedef vector<long long> vi;

#define endl '\n'

long long N, J;

vector<long long> primes;

pair<bool, long long> isPrime(long long test){
	bool prime = true;
	long long factor = 0;
	for(long long j = 0; j < primes.size(); j++){
		if(test % primes[j] == 0){
			prime = false;
			factor = primes[j];
			break;
		}
		if(primes[j]*primes[j] > test) break;
	}
	return make_pair(prime, factor);
}

bool testCoin(long long coin){
	bitset<16> x(coin);
	x[0] = 1;
	x[N-1] = 1;
	vector<long long> divisors;
	//cout << x << " ";
	for(long long i = 2; i <= 10; i++){
		long long curr = 0;
		long long power = 1;
		for(long long j = 0; j < 16; j++){
			if(x[j] != 0){
				curr += power;
			}
			power *= i;
		}
		pair<bool, long long> result = isPrime(curr);

		if(result.first){
			//cout << i << " " << curr << endl;
			return false;
		} else {
			divisors.push_back(result.second);
		}
	}
	cout << x << " ";
	for(long long i = 0; i < divisors.size(); i++){
		cout << divisors[i] << " ";
	}
	cout << endl;
	return true;
}

int main(){
	ios::sync_with_stdio(0);

	long long T; cin >> T;
	cin >> N >> J;

	for(long long i = 2; i < 10000000; i++){
		bool prime = true;
		for(long long j = 0; j < primes.size(); j++){
			if(i % primes[j] == 0){
				prime = false;
				break;
			}
			if(primes[j]*primes[j] > i) break;
		}
		if(prime) primes.push_back(i);
	}

	cout << "Case #1:" << endl;
	long long total = 0;
	for(long long i = 0; i < pow(2, N-2); i++){
		total += testCoin(i*2);
		if(total >= J) break;
	}
	
	return 0;
}