#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

struct point {
	double x, y, z;
	point(double x, double y, double z) : x(x), y(y), z(z) {}
	point() : x(0), y(0), z(0) {}
	double mag(){return sqrt(x*x+y*y+z*z);}
	//point operator/(const double& rhs){point(x/rhs,y/rhs,z/rhs);}
	bool operator<(const point& rhs) const {x==rhs.x ? y==rhs.y ? z<rhs.z : y<rhs.y:x<rhs.x;}
};

point operator/(const point &lhs, const double &rhs){
	return point(lhs.x/rhs,lhs.y/rhs,lhs.z/rhs);
}
point operator-(const point &lhs, const point &rhs){
	return point(lhs.x-rhs.x, lhs.y-rhs.y, lhs.z-rhs.z);
}

point cross(point A, point B){
	return point(A.y*B.z - A.z*B.y, A.z*B.x-A.x*B.z, A.x*B.y-A.y*B.x);
}

double dot(point A, point B){
	return A.x*B.x + A.y*B.y + A.z*B.z;
}

int main(){
	ios::sync_with_stdio(0);

	int n;
	while(cin >> n){
		double x, y, z; cin >> x >> y >> z;
		point carbon;
		vector<pair<int, point>> vals;
		point curr (x, y, z);
		if(n == 6){
			carbon = curr;
		} else {
			vals.push_back({n, curr});
		}
		for(int i = 0; i < 4; i++){
			int n1;
			double x1, y1, z1;
			cin >> n1 >> x1 >> y1 >> z1;
			point curr (x1, y1, z1);
			if(n1 == 6){
				carbon = curr;
			} else {
				vals.push_back({n1, curr});
			}
		}
		sort(vals.begin(), vals.end());
		if(vals[0].first == vals[1].first || vals[1].first == vals[2].first || vals[2].first == vals[3].first){
			cout << "No chiral centre" << endl;
			continue;
		}
		point B = vals[0].second - carbon;

		point maxProj = cross(B, cross(vals[3].second-carbon, B)/B.mag()) / B.mag();
		point nextProj = cross(B, cross(vals[2].second-carbon, B)/B.mag()) / B.mag();
		//cout << maxProj.x << " " << maxProj.y << " " << maxProj.z << endl;
		//cout << ((cross(vals[3].second, B))/B.mag()).x << " " << (cross(vals[3].second, B)).y << " " << (cross(vals[3].second, B)).z << " " <<endl;
		// if(abs(cross(maxProj, nextProj).mag()) < 1e-14){
		// 	cout << "No chiral centre" << endl;
		// } else 
		if(dot(cross(maxProj, nextProj), B) < 0){
			cout << "Rectus" << endl;
		// } else if(dot(cross(maxProj, nextProj), B) < 0){
		} else {
			cout << "Sinister" << endl;
		}
	}
	
	return 0;
}