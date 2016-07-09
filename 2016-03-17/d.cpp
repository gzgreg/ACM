#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'
int dX, dY, spd1, bonus;
int sX, sY, tX, tY;

double calcDist(double t){
	double Nx = tX * t / sqrt(tX*tX + tY*tY);
	double Ny = tY * t / sqrt(tX*tX + tY*tY);
	double Sx = sX + dX * t;
	double Sy = sY + dY * t;

	double a = (spd1*spd1 + dX*dX + dY*dY);
	double b = (2*Sx*dX - 2*Nx*dX + 2*Sy*dY - 2*Ny*dY);
	double c = (Nx*Nx + Sx*Sx - 2*Nx*Sx + Ny*Ny + Sy*Sy - 2*Ny*Sy);
	double t2 = (-b + sqrt(b*b - 4*a*c))/2/a;

	cout << t << " " << t2 << endl;
	return t+t2;
}

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	while(T--){
		cin >> sX >> sY >> dX >> dY;
		cin >> tX >> tY >> spd1 >> bonus;
		double spd2 = spd1 + bonus;
		double currT = sqrt(tX*tX + tY*tY) / spd2 / 2;
		double diff = currT / 2; 
		while(diff > 0.0001){
			int t1 = calcDist(currT - diff);
			int t2 = calcDist(currT);
			int t3 = calcDist(currT + diff);
			if(t1 > t2 && t1 > t3){
				currT = t1;
			} else if(t2 > t3){
				currT = t2;
			} else {
				currT = t3;
			}
			cout << currT << " " << diff << endl;
			diff /= 2;
		}
		cout << calcDist(currT) << endl;
	}
	
	return 0;
}