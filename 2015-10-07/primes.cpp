#include <bits/stdtr1c++.h>

using namespace std;

int primes[10000];
int size = 1;

bool isPrime(long);

int main(){
	int N; cin >> N;
	primes[0] = 2;
	for(long i = 3; i < 10000; i++){
		bool valid = false;
		for(int k = 0; k < size; k++){
			if(i % primes[k] == 0){
				break;
			} else if(sqrt(i) < primes[k]){
				valid = true;
				break;
			}
		}
		if(valid){
			primes[size] = i;
			size++;
		}
	}

	//check 1, 2-prime case
	if(isPrime(N)){
		cout << 1 << endl << N << endl;
		return 0;
	} else if(isPrime(N-2)){
		cout << 2 << endl << 2 << " " << N-2 << endl;
		return 0;
	}
	long i = 6;
	while(i < N){
		int inter = N - i;
		bool found;
		if(isPrime(inter)){
			for(int j = 0; j < size; j++){
				int currPrime = primes[j];
				if(currPrime > i){
					break;
				}
				else if(isPrime(i - currPrime)){
					found = true;
					cout << 3 << endl << inter << " " << currPrime << " " << i-currPrime;
					return 0;
				}
			}
		}
		i += 2;
	}

	return 0;
}

bool isPrime(long n){
	double root = sqrt(n);
	if(n % 2 == 0 && n != 2) return false;
	for(int i = 3; i < root+1; i += 2){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}