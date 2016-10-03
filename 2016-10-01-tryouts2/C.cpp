#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pii;
typedef vector<long long> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	
	long long T; cin >> T;
	while(T--) {
		long long ax, ay, bx, by, axa, aya, bxb, byb; cin >> ax >> ay >> bx >> by >> axa >> aya >> bxb >> byb;

		long long baseDist = 0;
		baseDist += abs(ax - axa) + abs(bx - bxb) + abs(ay - aya) + abs(by - byb);

		if(axa == ax && ax == bx && bx == bxb) {
			if(ay > by && aya < byb) baseDist += 2;
			if(ay < by && aya > byb) baseDist += 2;
		}
		if(aya == ay && ay == by && by == byb) {
			if(ax > bx && axa < bxb) baseDist += 2;
			if(ax < bx && axa > bxb) baseDist += 2;
		}

		cout << baseDist << endl;
	}

	return 0;
}