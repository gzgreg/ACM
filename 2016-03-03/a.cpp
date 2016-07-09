#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;
	long long num1 = 0, num2 = 0;
	for(int i = 0; i < n; i++){
		long long ai; cin >> ai;
		num1 = num1 | ai;
	}
	for(int i = 0; i < n; i++){
		long long bi; cin >> bi;
		num2 = num2 | bi;
	}

	cout << num1+num2 << endl;

	return 0;
}