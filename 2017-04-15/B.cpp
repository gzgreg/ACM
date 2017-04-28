#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;

#define pb push_back
const ll INF = 0x3f3f3f3f; const ld EPS = 1e-9; const ld PI = acos(-1.L);

namespace n3 {
//*/
const int D = 3;
typedef vector<ld> ndpt;
typedef list<ndpt>::iterator It;
struct Miniball { list<ndpt> L; int m; vector<vector<ld> > v, a; vector<ndpt> c;
  ndpt q0; vector<ld> r2, z, f; It end; ndpt c_c; ld c_r2;
  Miniball() : m(0),v(D+1,vector<ld>(D)),a(D+1,vector<ld>(D)),c(D+1,ndpt(D,0)),
    q0(D), r2(D+1), z(D+1), f(D+1), end(L.begin()), c_c(c[0]), c_r2(-1.L) {}
  void add(ndpt &p) { L.push_back(p); }
  void move_to_front(It i) { m--; if (end==i) end++; L.splice(L.begin(),L,i); }
  void mtf_mb(It i) { end=L.begin(); if (m==D+1) return;
    for (It k=L.begin(),j;(j=k++)!=i;) { ld e = get_e(j);
      if (e > 0 && push(*j)) mtf_mb(j), move_to_front(j); } }
  void pivot_mb(It i) {
    It t=++L.begin(), pivot; mtf_mb(t); ld max_e, old_r2=-1;
    do { if((max_e=max_excess(t,i,pivot)) > 0) {
      if ((t=end)==pivot) ++t;
      old_r2=c_r2; push(*pivot); mtf_mb(end); move_to_front(pivot); }
    } while (max_e > 0 && c_r2 > old_r2); }
  ld max_excess(It j,It i,It& pivot) { ld max_e=0,e;
    for (; j!=i;++j) if ((e=get_e(j)) > max_e) max_e=e,pivot=j; return max_e; }
  ld get_e(It j) { ld e=-c_r2; for (int i=0;i<D;++i) e+=pow((*j)[i]-c_c[i], 2);
    return e; }
  bool push(const ndpt& p) { int i, j; if (!m) c[0]=q0=p, r2[0]=0; else {
      for (i=0;i<D;++i) v[m][i]=p[i]-q0[i];
      for (i=1;i<m;++i) { a[m][i]=0;
        for (j=0;j<D;++j) a[m][i]+=v[i][j]*v[m][j];
        a[m][i]*=(2/z[i]); }
      for (i=1;i<m;++i) for (j=0;j<D;++j) v[m][j]-=a[m][i]*v[i][j];
      z[m]=0; for (j=0;j<D;++j) z[m]+=2*pow(v[m][j], 2);
      if (z[m] < c_r2*EPS) return false;
      ld e=-r2[m-1]; for (i=0;i<D;++i) e+=pow(p[i]-c[m-1][i], 2);
      f[m]=e/z[m];
      for (i=0;i<D;++i) c[m][i]=c[m-1][i]+f[m]*v[m][i];
      r2[m]=r2[m-1]+e*f[m]/2;
    } c_c=c[m]; c_r2=r2[m]; m++; return true; }
  void build(){ pivot_mb(L.end()); } };
//*!
}

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
////////////////////////////////////////////////////////////////////////////////
// 3D convex hull and volume (TESTED: Chicago2013, O(n^2))
////////////////////////////////////////////////////////////////////////////////
//*!
namespace n2 {
//*/
struct face{int a, b, c;}; int t, n; vector<p3d> v;
ld dist(const face &f, const p3d p) {
  return dot(cross(v[f.b]-v[f.a], v[f.c]-v[f.b]), p-v[f.a]); }
ld area(const face &f){ return abs(cross(v[f.b] - v[f.a], v[f.c] - v[f.a])); }
ld volume(const face &f){ p3d n=cross(v[f.b]-v[f.a], v[f.c]-v[f.b]);
  return area(f)*dot(n/abs(n), v[f.a])/6; }
void convex_hull_clean_input() { random_shuffle(v.begin(), v.end());
  for(int i=n-1; i>=0; i--) v[i] = v[i] - v[0];
  for(int i=1; i<n; i++) if(abs(v[i]-v[0]) > EPS) { swap(v[i], v[1]); break; }
  for(int i=2; i<n; i++) if(abs(cross(v[1] - v[0], v[i] - v[0])) > EPS) {
    swap(v[i], v[2]); break; }
  for(int i=3; i<n; i++) { p3d n = cross(v[1] - v[0], v[2] - v[0]);
    if(abs(dot(n, v[0] - v[i])) > EPS) { swap(v[i], v[3]); break; } } }
void main2(){ cin >> n; // outputs area/volume of the CH in 3D
  v.resize(n); for(int i=0; i<n; i++) cin >> v[i].x >> v[i].y >> v[i].z;
  convex_hull_clean_input();
  vector<face> f { {0, 1, 2}, {2, 1, 0} };
  for(int i=3; i<n; i++){ vector<face> nxt; set<int> edge;
    for(auto ff : f) // remove the faces
      if(dist(ff, v[i]) > EPS) { // above
        edge.insert((ff.a << 10) | ff.b);
        edge.insert((ff.b << 10) | ff.c);
        edge.insert((ff.c << 10) | ff.a);
      } else nxt.push_back(ff); // change shift and mask values for >1024 verts
    for(auto e : edge) if(!edge.count( ((e & 1023) << 10) | (e >> 10) ))
      nxt.push_back(face{e >> 10, e & 1023, i});
    f = nxt; }

  ld optimal = 1e15;
  for(auto ff : f) {
  	p3d norm = cross(v[ff.a] - v[ff.b], v[ff.a] - v[ff.c]);
  	norm = norm / abs(norm);
  	ld maxDist = 0;
  	int maxId = 0;
  	for(int i = 0; i < v.size(); i++) {
  		ld currDist = abs(dot(norm, v[i]) - dot(norm, v[ff.a])) / abs(norm);
  		if(currDist > maxDist) {
  			maxDist = currDist;
  			maxId = i;
  		}
  	}

  	vector<p3d> projected;
  	for(int i = 0; i < v.size(); i++) {
  		p3d proj;
  		proj = v[i] - dot(v[i] - v[ff.a], norm)*norm;
  		projected.push_back(proj);
  	}

  	n3::Miniball mb;
  	for(auto pt : projected) {
  		n3::ndpt p(3); 
  		p[0] = pt.x; p[1] = pt.y; p[2] = pt.z;
  		mb.add(p);
  	}
  	mb.build();
  	optimal = min(optimal, maxDist * mb.c_r2 * PI);
  }
  cout << fixed << setprecision(10) << optimal << endl;
	}
  
}


int main(){
	ios::sync_with_stdio(0);
	
	n2::main2();

	return 0;
}