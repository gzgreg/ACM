#include <bits/stdc++.h>

using namespace std;

pair<double, double> intersect(double x1, double y1, int A, int B, double x2, double y2){
	double xp = x2*(B*x1 - A*y1)/(x2*y1 - y2*x1) + A;
	double yp = y2*(B*x1 - A*y1)/(x2*y1 - y2*x1) + B;
	return make_pair(xp, yp);
}

complex<double> i (0, 1);

int main(){
	ios::sync_with_stdio(0);

	int Ax, Ay, Bx, By, Cx, Cy;
	cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;
	while(Ax != 0){
		int ACx = Cx-Ax, ABx = Ax-Bx, ACy = Cy-Ay, ABy = Ay-By;
		int CBx = Bx-Cx, CBy = By-Cy;
		complex<double> AC (ACx, ACy), AB (ABx, ABy), CB (CBx, CBy);
		double top = min(abs(arg(AB) - arg(AC)), min(abs(arg(AB) - arg(CB)), abs(arg(AC) - arg(CB))));
		double bot = 0;
		double diff = top / 2;
		double outx, outy;
		while(diff > 0.0005){
			double theta = (top+bot) / 2;
			//intersect lines out of a and b
			complex<double> ACrot = AC*exp(-i*theta);
			complex<double> ABrot = AB*exp(-i*theta);
			pair<double, double> pt = intersect(real(ACrot), imag(ACrot), ABx, ABy, real(ABrot), imag(ABrot));
			int Cptx = pt.first - Cx, Cpty = pt.second - Cy;
			complex<double> Cpt (pt.first - Cx, pt.second - Cy);
			if(abs(arg(Cpt) - arg(CB)) > theta){
				top -= diff;
			} else {
				bot += diff;
			}
			diff /= 2;
			cout << abs(arg(Cpt) - arg(CB)) << " " << theta <<  endl;
			if(diff <= 0.0005){
				outx = pt.first + Ax;
				outy = pt.second + Ay;
			}
		}

		cout << fixed << setprecision(2) << outx << " " << outy << endl;

		cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;
	}

	return 0;
}