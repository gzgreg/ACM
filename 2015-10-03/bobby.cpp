#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

using namespace std;

int main(){
	int factorial[20]; factorial[1] = 1; factorial[0] = 1;
	for(int i = 2; i < 20; i++){
		factorial[i] = factorial[i-1] * i;
	}
	int N; cin >> N;
	for(int i = 0; i < N; i++){
		int R, S, X, Y, W;
		cin >> R >> S >> X >> Y >> W;
		double O = (double)(S - R + 1) / S;
		double odds = 0;
		for(int j = 0; j <= Y-X; j++){
			odds += pow(O, Y-j)*pow(1-O, j) * factorial[Y] / factorial[j] / factorial[Y-j];
		}

		if(W*odds > 1){
			if(abs(W*odds - 1) <= 1e-10) cout << "no" << endl; else cout << "yes" << endl;
		} else cout<<"no" << endl;
	}
	return 0;
}