#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

using namespace std;

int main(){
	int N; cin >> N;
	string alphabet = "0123456789abcdefghijklmnopqrstuvwxyz";
	for(int i = 0; i < N; i++){
		string first, second, op, final, junk;
		cin >> first >> op >> second >> junk >> final;
		bool invalid = true;
		for(int base = 1; base <= 36; base++){
			long long firstI = 0, secondI = 0, finalI = 0;
			bool invalidB = false;
			for(int k = 0; k < first.size(); k++){
				int power = first.size() - k - 1;
				long long currVal = alphabet.find(first[k])*pow(base, power);
				if(currVal > pow(2, 32) - 1 || (alphabet.find(first[k]) > base-1 && base != 1) || (base == 1 && alphabet.find(first[k]) != 1)){
					invalidB = true;
					break;
				} else {
					firstI += currVal;
				}
			}
			for(int k = 0; k < second.size(); k++){
				int power = second.size() - k - 1;
				long long currVal = alphabet.find(second[k])*pow(base, power);
				if(currVal > pow(2, 32) - 1 || (alphabet.find(second[k]) > base-1 && base != 1) || (base == 1 && alphabet.find(second[k]) != 1)){
					invalidB = true;
					break;
				} else {
					secondI += currVal;
				}
			}
			for(int k = 0; k < final.size(); k++){
				int power = final.size() - k - 1;
				long long currVal = alphabet.find(final[k])*pow(base, power);
				if(currVal > pow(2, 32) - 1 || (alphabet.find(final[k]) > base-1 && base != 1) || (base == 1 && alphabet.find(final[k]) != 1)){
					invalidB = true;
					break;
				} else {
					finalI += currVal;
				}
			}
			if(firstI > pow(2, 32) - 1 || secondI > pow(2, 32) - 1 || finalI > pow(2, 32) - 1) invalidB = true;
			//cout << firstI << " " << secondI << " " << finalI << " " << base << endl;
			if(invalidB) continue;

			if(op == "+"){
				if(firstI + secondI == finalI){
					if(base == 36){
						cout << 0;
					} else {
						cout << alphabet[base];
					}
					invalid = false;
				}
			} else if(op == "-"){
				if(firstI - secondI == finalI){
					if(base == 36){
						cout << 0;
					} else {
						cout << alphabet[base];
					}
					invalid = false;
				}
			} else if(op == "*"){
				if(firstI * secondI == finalI){
					if(base == 36){
						cout << 0;
					} else {
						cout << alphabet[base];
					}
					invalid = false;
				}
			} else if(op == "/"){
				if(abs((double)firstI / secondI - finalI) <= 1e-10){
					if(base == 36){
						cout << 0;
					} else {
						cout << alphabet[base];
					}
					invalid = false;
				}
			} 
		}
		if(invalid){
			cout << "invalid" << endl;
			continue;
		} else cout << endl;
	}

}