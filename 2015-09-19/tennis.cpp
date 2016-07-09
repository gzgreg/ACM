using namespace std;

#include <iostream>
#include <iomanip>
#include <math.h>

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		double p;
		cin >> p;
		double l = 1-p;
		cout << setprecision(5) << fixed << pow(p, 4)*(1 + 4*l + 10*l*l) + 20*pow(p, 5)*pow(l, 3) / (1 - 2*p*l) << endl;
	}	
}