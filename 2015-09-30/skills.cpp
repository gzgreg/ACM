#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int skills[n];
	int toTen[n];
	int remaining = 0;
	int rating = 0;
	for(int i = 0; i < n; i++){
		cin >> skills[i];
		toTen[i] = skills[i] % 10 == 0 ? 1000 : 10 - skills[i] % 10;
		remaining += 100 - skills[i] + (skills[i] % 10 == 0 ? 0 : skills[i] % 10 - 10);
		rating += floor(skills[i] / 10);
	}

	sort(toTen, toTen + n);
	int i = 0;
	while(k > 0){
		int currVal = toTen[i];
		if(currVal != 1000 && i < n){
			if(k < currVal) break;
			rating += 1;
			k -= toTen[i];
			i++;
		} else {
			if(remaining > k){
				rating += k / 10;
			} else rating += remaining / 10;
			break;
		}
	}

	cout << rating;
	return 0;
}