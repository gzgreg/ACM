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
		double a, b, Z, n;
		cin >> a >> b >> Z >> n;
		double answer = Z;
		for(int j = 0; j < n; j++){
			answer = answer * a + b;
		}
		cout << setprecision(3) << fixed << answer << endl;
	}
	return 0;
}