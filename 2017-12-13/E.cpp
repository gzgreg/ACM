#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct p3d{ ld x,y,z; friend ostream& operator<< (ostream& os, const p3d& p) {
  return os << "(" << p.x << "," << p.y << "," << p.z << ")"; } };
ld abs(const p3d &v){ return sqrt(v.x*v.x + v.y*v.y + v.z*v.z); }
p3d operator+(const p3d&a,const p3d&b){ return {a.x+b.x,a.y+b.y,a.z+b.z}; }
p3d operator-(const p3d&a,const p3d&b){ return {a.x-b.x,a.y-b.y,a.z-b.z}; }
p3d operator*(const ld &s, const p3d &v){ return {s*v.x, s*v.y, s*v.z}; }
p3d operator/(const p3d&v, const ld &s){ return {v.x/s, v.y/s, v.z/s}; }
inline ld dot(const p3d &a, const p3d &b){ return a.x*b.x + a.y*b.y + a.z*b.z; }
inline p3d cross(const p3d &a, const p3d &b){
  return {a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x}; }
inline ld dist(const p3d &s, const p3d &p) {
  return (p.x-s.x)*(p.x-s.x) + (p.y-s.y)*(p.y-s.y) + (p.z-s.z)*(p.z-s.z); }
// plane/line intersection. p - pt on plane, n - normal, a1 -> a2 : line
inline p3d pl_inter(const p3d &p, const p3d &n, const p3d &a1, const p3d &a2){
  return a1 + dot(p - a1, n)/dot(n, a2 - a1)*(a2 - a1); }
////////////////////////////////////////////////////////////////////////////////
// CCW 3D rotation about arbitrary axis; tested on 2009 pacnw D but pray anyway
////////////////////////////////////////////////////////////////////////////////
inline p3d rotate(const p3d& p /*pt*/, const p3d& u /*axis*/, const ld& angle) {
  ld c = cos(angle), s = sin(angle), t = 1 - cos(angle);  return {
    p.x*(t*u.x*u.x + c) + p.y*(t*u.x*u.y - s*u.z) + p.z*(t*u.x*u.z + s*u.y),
    p.x*(t*u.x*u.y + s*u.z) + p.y*(t*u.y*u.y + c) + p.z*(t*u.y*u.z - s*u.x),
    p.x*(t*u.x*u.z - s*u.y) + p.y*(t*u.y*u.z + s*u.x) + p.z*(t*u.z*u.z + c) }; }

p3d getNorm(p3d a, p3d b, p3d c) {
	return cross(b-a, b-c);
}

bool isLeft(p3d a, p3d b, p3d c, p3d p) {
	p3d norm = getNorm(a, b, c);
	return dot(norm, b-p) > 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;

	vector<pair<ld, p3d>> points;

	for(int i = 0; i < N; i++) {
		ld prob; cin >> prob;
		int x, y, z; cin >> x >> y >> z;
		p3d pt;
		pt.x = x;
		pt.y = y;
		pt.z = z;
		points.push_back({prob, pt});
	}
	vector<ld> prob(N);

	double prob3d = 1;
	double probNoPoints = 1;
	for(int i = 0; i < N; i++) {
		probNoPoints *= 1 - points[i].first;
	}
	prob3d -= probNoPoints;
	ld ans = 0;
	for(int i = 0; i < N; i++) {
		ld curProb = points[i].first;
		for(int j = 0; j < N; j++) {
			if(i == j) continue;
			curProb *= 1 - points[j].first;
		}
		ans += curProb;
		prob3d -= curProb;
	}
	for(int i = 0; i < N; i++) {
		for(int j = i+1; j < N; j++) {
			ld curProb = points[i].first;
			curProb *= points[j].first;
			for(int k = 0; k < N; k++) {
				if(k == i || k == j) continue;
				curProb *= 1 - points[k].first;
			}

			ans += 2 * curProb;
			prob3d -= curProb;
		}
	}
	ld F = 0, E = 0;
	for(int i = 0; i < N; i++) {
		for(int j = i+1; j < N; j++) {
			for(int k = j+1; k < N; k++) {
				set<int> left, right;
				for(int pt = 0; pt < N; pt++) {
					if(pt == i
						|| pt == j
						|| pt == k) {
						continue;
					}
					if(isLeft(points[i].second, 
							points[j].second, 
							points[k].second, 
							points[pt].second))
					{
						left.insert(pt);
					} else {
						right.insert(pt);
					}
				}
				ld curProb = 1;
				for(auto cur : left) {
					curProb *= 1 - points[cur].first;
				}
				curProb *= points[i].first;
				curProb *= points[j].first;
				curProb *= points[k].first;
				F += curProb;

				curProb = 1;
				for(auto cur : right) {
					curProb *= 1 - points[cur].first;
				}
				curProb *= points[i].first;
				curProb *= points[j].first;
				curProb *= points[k].first;
				F += curProb;
				for(auto cur : left) {
					curProb *= 1 - points[cur].first;
				}
				F -= 2*curProb;
				ans += 3*curProb;
				prob3d -= curProb;
			}
		}
	}
	p3d ZERO_PT;
	ZERO_PT.x = 0;
	ZERO_PT.y = 0;
	ZERO_PT.z = 0;
	for(int i = 0; i < N; i++) {
		for(int j = i+1; j < N; j++) {
			for(int k = 0; k < N; k++) {
				if(k == i || k == j) continue;
				for(int l = k+1; l < N; l++) {
					if(l == i || l == j) continue;
					ld curProb = 1;
					curProb *= points[i].first;
					curProb *= points[j].first;
					curProb *= points[k].first;
					curProb *= points[l].first;
					p3d norm1 = getNorm(points[i].second, 
						points[j].second, 
						points[k].second);
					p3d norm2 = getNorm(points[i].second,
						points[j].second,
						points[l].second);
					if(dot(norm1, points[l].second - points[i].second) < 0) {
						norm1 = ZERO_PT-norm1;
					}
					if(dot(norm2, points[k].second - points[i].second) < 0) {
						norm2 = ZERO_PT-norm2;
					} 
					for(int m = 0; m < N; m++) {
						if(m == i || m == j || m == k || m == l) continue;
						if(dot(norm1, points[m].second - points[i].second) < 0
							|| dot(norm2, points[m].second - points[i].second) < 0) {
							curProb *= 1 - points[m].first;
						}
					}
					E += curProb;
				}
			}
		}
	}
	if(prob3d < 1e-10) {
		cout << fixed << setprecision(10) << ans << endl;
		return 0;
	}
	E /= prob3d;
	F /= prob3d;
	ans += (2 + E - F)*prob3d;

	cout << fixed << setprecision(10) << ans << endl;
	
	return 0;
}