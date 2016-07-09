#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

using namespace std;

int main(){
	int n; cin >> n;
	int floors[n];
	int temp[n];
	for(int i = 0; i < n; i++){
		cin >> floors[i];
	}
	temp[n - 1] = floors[n - 1];
	for(int i = n - 2; i >= 0; i--){
		if(floors[i] > temp[i+1]){
			temp[i] = floors[i];
		} else temp[i] = temp[i+1];
	}
	for(int i = 0; i < n; i++){
		int toAdd = temp[i] != floors[i] ? temp[i] - floors[i] + 1 : i == n-1 || temp[i] != temp[i+1] ? 0:1;
		cout << toAdd << " ";
	}
	return 0;
}