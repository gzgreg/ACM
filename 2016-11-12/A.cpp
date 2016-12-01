#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;

	while(T--) {
		long long cInt, dInt; cin >> cInt >> dInt;
		bitset<32> C(cInt), D(dInt);
		bitset<32> a (0), b (0);
		bool diffFound = false;
		bool valid = true;
		for(int i = 31; i >= 0; i--) {
			if(C[i] && D[i]) {
				a.set(i);
				b.set(i);
			} else if (!C[i] && !D[i]) {
				a.reset(i);
				b.reset(i);
			} else if(!C[i] && D[i]) {
				if(diffFound) {
					a.set(i);
					b.reset(i);
				} else {
					diffFound = true;
					a.reset(i);
					b.set(i);
				}
			} else {
				cout << -1 << endl;
				valid = false;
				break;
			}
		}
		if(!valid) continue;
		cout << a.to_ulong() << " " << b.to_ulong() << endl;
	}
	
	return 0;
}