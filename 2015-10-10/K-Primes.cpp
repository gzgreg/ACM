#include <bits/stdtr1c++.h>

using namespace std;

bool isPrime(long);

int main(){
	long N; cin >> N;
	if(!isPrime(N)){
		cout << "no";
		return 0;
	}
	long nflip = 0; int size = floor(log(N) / log(10))+1;
	for(int i = 0; i < size; i++){
		int digit = N % 10;
		int newDigit;
		switch(digit){
			case 0:
			case 1:
			case 2:
			case 5:
			case 8:
				newDigit = digit;
				break;
			case 6:
				newDigit = 9;
				break;
			case 9:
				newDigit = 6;
				break;
			case 3:
			case 4:
			case 7:
				cout << "no";
				return 0;
				break;
		}
		nflip += newDigit * pow(10, size - 1 - i);
		N /= 10;
	}

	if(!isPrime(nflip)){
		cout << "no";
		return 0;
	}
	cout << "yes";
	return 0;
}

bool isPrime(long n){
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