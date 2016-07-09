#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

using namespace std;

int main(){
	int N; cin >> N;
	string curr; getline(cin, curr);
	string letters = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
	for(int i = 0; i < N; i++){
		getline(cin, curr);
		bool pangram = true;
		for(int j = 0; j < 26; j++){
			if(curr.find(letters[2*j]) == string::npos && curr.find(letters[2*j+1]) == string::npos){
				if(pangram){
					pangram = false;
					cout << "missing ";
				}
				cout << letters[2*j];
			}
		}

		if(pangram) cout << "pangram";
		cout << endl;
	}
	return 0;
}