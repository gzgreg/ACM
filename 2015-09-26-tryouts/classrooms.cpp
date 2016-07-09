using namespace std;

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

long long factorial(int);

int main(){
	int n, r;
	cin >> n;
	while(n != 0){
		cin >> r;
		int maxRels = factorial(n/2 - 1);
		int class1[maxRels];
		int class2[maxRels];
		int class1idx = 0;
		int class2idx = 0;
		for(int i = 0; i < r; i++){
			int val;
			int temp;
			cin >> temp; 
			int sub;
			if(temp > n/2) sub = n/2; else sub = 0;
			val = (temp-sub)*10; cin >> temp; val += (temp - sub);
			if(temp > n/2) class2[class2idx] = val; class2idx++; else class1[class1idx] = val; class1idx++;
		}
		sort(class1, class1 + class1idx + 1);
		sort(class2, class2 + class2idx + 1);
		int class1Combo = factorial(n/2);
		int class2Combo = factorial(n/2);
		for(int i = 0; i <= class1idx; i++){
			int val = class1[class1idx];
		}
		

		cin >> n;
	}
	return 0;
}

long long factorial(int n){
	long long out = 1;
	for(int i = 1; i <= n; i++){
		out = out * i;
	}
	return out;
}