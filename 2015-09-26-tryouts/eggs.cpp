using namespace std;

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

#define SIZE 100000

int main(){
	int N;
	int validNums[SIZE];
	fill_n(validNums, validNums + SIZE, 0);
	validNums[0] = 2;
	int idx = 1;
	cout << idx;
	for(int i = 3; i <= SIZE; i++){
		bool valid = true;
		for(int j = 0; j <= SIZE; j++){
			if (validNums[j] == 0 || validNums[j] >= sqrt(i)){
				break;
			} else if(i % validNums[j] == 0) {
				bool valid = false;
				break;
			}
		}
		if(valid){
			validNums[idx] = i;
			idx++;
		}
	}
	for (int i = 0; i < SIZE; i++){
		if(validNums[i] * validNums[i] > SIZE) break;
		validNums[idx] = validNums[i] * validNums[i];
		idx++;
	}
	for(int i = 0; i < 10000; i++){
		cout << validNums[i] << " ";
	}
	cin >> N;
	return 0;
}