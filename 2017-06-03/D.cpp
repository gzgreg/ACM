#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int memo[10006];

bool happy(int input) {
	if(input == 1) return true;
	if(memo[input] != -1) {
		return memo[input];
	}
	memo[input] = false;
	int newNum = 0;
	int exp = 1;
	for(int i = 0; i < 6; i++) {
		int curr = (input / exp) % 10;
		newNum += curr * curr;
		exp *= 10;
	}
	return memo[input] = happy(newNum);
}

bool prime(int input) {
	if(input == 1) return false;
	for(int i = 2; i < sqrt(input) + 1; i++) {
		if(input % i == 0) {
			return false;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);

	int P; cin >> P;

	memset(memo, -1, sizeof memo);

	while(P--) {
		int K; cin >> K;
		int num; cin >> num;

		cout << K << " " << num << " ";
		if(happy(num) && prime(num)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}