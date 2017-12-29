#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 2147483647

int main(){	
	ll a = 512, b = 191;
	int ans1 = 0, ans2 = 0;

	// part 1
	for(int i = 0; i < 40000000; i++) {
		a *= 16807;
		a %= MOD;
		b *= 48271;
		b %= MOD;

		bitset<16> tmp1(a), tmp2(b);
		if(tmp1 == tmp2) {
			ans1++;
		}
	}
	// part 2
	for(int i = 0; i < 5000000; i++) {
		do {
			a *= 16807;
			a %= MOD;
		} while(a % 4 != 0);
		do {
			b *= 48271;
			b %= MOD;
		} while(b % 8 != 0);

		bitset<16> tmp1(a), tmp2(b);
		if(tmp1 == tmp2) {
			ans2++;
		}
	}

	cout << ans1 << " " << ans2 << endl;

	return 0;
}