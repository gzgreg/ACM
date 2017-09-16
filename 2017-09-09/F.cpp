#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

ld fib[1400];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fib[0] = 0;
	fib[1] = 1;

	for(int i = 2; i < 100; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}

	for(int i = 4; i < 100; i++) {
		cout << i << " " << fib[i] * i * (i+1) / 2 << endl;
	}

	return 0;
}