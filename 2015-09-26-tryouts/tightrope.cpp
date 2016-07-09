using namespace std;

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

int main(){
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		double m, b;
		cin >> b >> m;
		double A = b + m/2;
		cout << setprecision(1) << fixed << (1 - (m / 6 + b / 2)) / (1 - A) << endl;
	}
	return 0;
}