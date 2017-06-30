#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	int n, a; cin >> n >> a;
	double best = -1000;
	int bestIdx;
	for(int i = 2; i < n; i++) {
		double angle = (double) 180 * (n-i) / n;
		if(abs(angle - a) < abs(best - a)) {
			best = angle;
			bestIdx = i;
		}
	}

	cout << "1 2 " << bestIdx + 1<< endl;
	
	return 0;
}