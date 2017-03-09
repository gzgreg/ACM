#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<ld> pt;

ld minDist(complex<ld> v, complex<ld> w, complex<ld> p) {
  const ld l2 = norm(v-w);

  const ld t = max(0.0L, min(1.0L, (conj(p-v) * (w-v)).real() / l2));
  const complex<ld> proj = v + t * (w - v);  // Projection falls on the segment
  return abs(p-proj);
}

ld cross(pt v1, pt v2) {
	return v1.real()*v2.imag() - v1.imag()*v2.real();
}

int main(){
	ios::sync_with_stdio(0);
	
	int n; cin >> n;

	vector<pt> vertices;
	for(int i = 0; i < n; i++) {
		int x, y; cin >> x >> y; vertices.push_back(pt(x, y));
	}

	vector<pt> centers;

	for(int i = 0; i < n; i++) {
		pt v1 = vertices[(i+n-1) % n];
		pt v2 = vertices[i];
		pt v3 = vertices[(i+1) % n];
		if(cross(v2-v1, v2-v3) <= 0) continue;

		pt side1 = v1-v2;
		pt side2 = v3-v2;

		ld angle = asin(cross(side1, side2) / abs(side1) / abs(side2));

		pt center = 4000 / tan(angle/2) * (side1 / abs(side1)) + (side1 / abs(side1) * complex<ld>(0, 1) * 4000.0L) + v2;
		//cout << i << " " << center << " " << angle << " " << side1 << endl;
		bool success = true;
		for(int j = 0; j < n; j++) {
			if(minDist(vertices[j], vertices[(j+1) % n], center) < 3999) {
				success = false;
				break;
			}
		}
		if(!success) continue;
		centers.push_back(center);
	}

	for(int i = 0; i < centers.size(); i++) {
		for(int j = i + 1; j < centers.size(); j++) {
			if(abs(centers[i] - centers[j]) >= 7999) {
				cout << fixed << setprecision(10);
				cout << centers[i].real() << " " << centers[i].imag() << endl;
				cout << centers[j].real() << " " << centers[j].imag() << endl;
				return 0;
			}
		}
	}

	cout << "impossible" << endl;

	return 0;
}