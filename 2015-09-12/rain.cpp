using namespace std;

#include <iostream>
#include <iomanip>
#include <math.h>
#define PI 3.14159265358979

void cout2(double);

int main(){
	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		int s, r;
		cin >> s >> r;
		
		if(s >= r*2){
			cout2(PI*r*r);
		} else if(s*1.41421356237 / 2 < r){
			cout2(s*s);
		} else {
			double ans = PI*r*r - 4*(r*r*acos((double)s/2/r) - s / 2.0 * sqrt(r*r - s*s/4.0));
			cout2(ans);
		}
		cout << "\n";
	}	
}

void cout2(double num){
	cout << fixed << setprecision(2) << num;
}