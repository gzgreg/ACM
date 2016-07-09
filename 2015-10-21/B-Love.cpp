#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long n);

int main(){
	long long n; cin >> n;
	if(isPrime(n)){
		cout << n;
		return 0;
	}
	long long value = 1;
	map<long long, int> mult;
	for(long long i = 2; i <= floor(sqrt(n)) + 1; i++){
		if(n%i == 0){
			if(isPrime(i)){
				value *= i;
				int currMult = 1;
				long long currVal = n / i;
				while(currVal % i == 0){
					currVal /= i;
					currMult++;
				}
				mult.insert(make_pair(i, currMult));
			}
		}
	}
	long long newPrime = n;
	for(std::map<long long,int>::iterator it=mult.begin(); it != mult.end(); it++){
		while(newPrime % it->first == 0){
			newPrime = newPrime / it->first;
		}
	}
	value *= newPrime;
	cout << value;

	return 0;
}

bool isPrime(long long n){
	if(n == 1) return false;
	double root = sqrt(n);
	if(n % 2 == 0 && n != 2) return false;
	for(int i = 3; i < root+1; i += 2){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}