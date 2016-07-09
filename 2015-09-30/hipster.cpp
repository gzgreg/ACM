#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

using namespace std;

int main(){
	int a[2];
	cin >> a[0] >> a[1];
	sort(a, a+2);



	int max = a[0];
	int next = floor((a[1] - a[0]) / 2);
	cout << max << " " << next;

	return 0;
}