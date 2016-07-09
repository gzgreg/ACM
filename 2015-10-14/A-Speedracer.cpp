#include <bits/stdtr1c++.h>

using namespace std;

#define EPSILON 1e-6

int main(){
	double a, b, c, d, m, t;
	while(cin >> a >> b >> c >> d >> m >> t){
		double guess = 500;
		double diff = 250;
		double result = (a * guess * guess * guess + b * guess * guess + c * guess + d) * m;

		while(abs(result - t) > EPSILON){
			if(result > t){
				guess -= diff;
			} else {
				guess += diff;
			}
			diff /= 2;
			result = (a * guess * guess * guess + b * guess * guess + c * guess + d) * m;
		}

		guess = floor(guess * 100) / 100;

		cout << setprecision(2) << fixed << guess << endl;
	} 
	

	return 0;
}