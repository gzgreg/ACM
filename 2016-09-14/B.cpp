#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

long long factorial(int max, int min) {
	long long ans = 1;
	for(int i = min; i <= max; i++) {
		ans *= i;
	}
	return ans;
}

long long calculate(int lSteps, int sSteps) {
	int totalSteps = lSteps + sSteps;
	long long ans = 1;
	int idx = 2;
	for(int i = max(lSteps, sSteps) + 1; i <= lSteps + sSteps; i++) {
		ans *= i;
		while(ans % idx == 0 && idx <= min(lSteps, sSteps)) {
			ans /= idx;
			idx++;
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);

	int P; cin >> P;
	while(P--) {
		int K; cin >> K;
		int s; cin >> s;

		cout << K << " ";

		if(s%2 == 1) {
			cout << 0 << endl;
			continue;
		}
		long long total = 0;

		for(int i = 4; i <= s; i += 4) {
			if((i / 4) < (s - i) / 2) continue;

			total += calculate(i / 4, (s-i) / 2) * calculate(i / 4, (s-i) / 2);
		}

		cout << total << endl;
	}
	
	return 0;
}