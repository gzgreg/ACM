#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int x1, y1, x2, y2;
	int vx1, vy1, vx2, vy2;

	cin >> x1 >> y1 >> x2 >> y2 >> vx1 >> vy1 >> vx2 >> vy2;

	int xnet = x1 - x2;
	int ynet = y1 - y2;

	int vxnet = vx1 - vx2;
	int vynet = vy1 - vy2;

	if(xnet*vxnet + ynet*vynet >= 0) {
		cout << fixed << setprecision(10) << sqrt(xnet*xnet + ynet*ynet) << endl;
	} else {
		int xproj = -vynet;
		int yproj = vxnet;

		double dist = abs(xproj*xnet + yproj*ynet) / sqrt(xproj*xproj + yproj*yproj);
		cout << fixed << setprecision(10) << dist << endl;
	}
	
	return 0;
}