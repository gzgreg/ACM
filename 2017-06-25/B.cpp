#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	
	int m, b; cin >> m >> b;

	ll total = 0;
	ll maxTotal = 0;
	for(int i = 0; i <= b; i++) {
		total += i;
	}
	maxTotal = total;
	for(int i = 1; i <= b*m; i++) {
		if((i-1) % m == 0) {
			ll yDel = -(i-1) / m + b;
			ll maxX = i-1;
			total -= yDel * (maxX+1);
			total -= maxX*(maxX+1) / 2;
		}
		ll maxY = -((i+m-1)/ m) + b;
		ll xDel = i;
		//cout << maxY << " " << xDel << endl;
		total += xDel*(maxY+1);
		total += maxY*(maxY+1) / 2;
		//cout << i << " " << total<< endl;
		maxTotal = max(maxTotal, total);
	}

	cout << maxTotal << endl;

	return 0;
}