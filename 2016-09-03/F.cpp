#include <bits/stdc++.h>

using namespace std;

int solve (int i, int num, bool first) {
	if (first) {
		if (i % 2 == 0) return i / 2;
		else return solve(i/2 + 1, (num+1)/2, num % 2 ? !first : first) + (num)/2;
	} else {
		if (i % 2 == 1) return i/2 + 1;
		else return solve(i/2, num/2, num % 2 ? !first : first) + (num+1)/2;
	}
}

int main() {
	int T; cin >> T;
	for (int k=0; k<T; k++) {
		int i, N; cin >> N >> i;
		cout << solve(i, N, false) << endl;
	}
}
