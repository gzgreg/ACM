#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

using namespace std;

int main(){
	int N; cin >> N;
	string curr;
	getline(cin, curr);
	int squares[102];
	for(int i = 0; i < 101; i++){
		squares[i] = i*i;
	}
	for(int i = 0; i < N; i++){
		getline(cin, curr);
		int length = curr.length();
		int sqr = 1;
		while(length > squares[sqr]) sqr++;

		string encoded = ""; 
		for(int j = 0; j < squares[sqr]; j++){
			encoded.push_back('*');
		} 
		for(int j = 0; j < length; j++){
			encoded[j] = curr[j];
		}
		string encoded2 = "";
		for(int k = 0; k < sqr; k++){
			for(int j = sqr - 1; j >= 0; j--){
				char value = encoded[j*sqr + k];
				if(value != '*'){
					encoded2.push_back(value);
				}
			}
		}
		cout << encoded2 << endl;

	}


	return 0;
}