#include <bits/stdc++.h> // if using g++, this includes ALL headers.

//*!
using namespace std;
typedef long long ll;
typedef double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
#define pb push_back
namespace std {
template<class T>inline bool operator<(const complex<T>& a,const complex<T>& b){
  return a.real()<b.real() || (a.real() == b.real() && a.imag()<b.imag()); } };
const int MAXN=50, MAXM=50, N=50, M=50;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
//*/
// ios::sync_with_stdio(0); cin.tie(0); // faster io, but unsyncs with cstdio
const ll INF = 0x3f3f3f3f; const ld EPS = 1e-9; const ld PI = acos(-1.L);
////////////////////////////////////////////////////////////////////////////////
// General 2D geometry, Polygon cutting, Point in polygon
////////////////////////////////////////////////////////////////////////////////
ld cp(const pt& a, const pt& b) { return imag(conj(a)*b); }
ld dp(const pt& a, const pt& b) { return real(conj(a)*b); }
// dist(const pt& a, const pt& b) ==> abs(a-b)
inline ld sgn(const ld& x) { return abs(x) < EPS ? 0 : x/abs(x); }
inline bool cmp_lex(const pt& a, const pt& b) {
  return a.real() < b.real() || (a.real() == b.real() && a.imag() < b.imag()); }
inline bool cmp_lex_i(const pt& a, const pt& b) {
  return a.imag() < b.imag() || (a.imag() == b.imag() && a.real() < b.real()); }
 
// Area of a polygon (convex or concave). Always non-negative.
ld area(const pol &v) { ld s = 0; int n = v.size();
  for(int i = n-1, j = 0; j < n; i = j++) s += cp(v[i], v[j]); return abs(s)/2;}
 
// orientation does not matter
pt centroid(const pol &v) {
  pt res; ld A = 0; int n = v.size();
  for(int i=n-1,j=0;j<n;i=j++) A+=cp(v[i],v[j]), res+=(v[i]+v[j])*cp(v[i],v[j]);
  return abs(A) < EPS ? res : res/3./A; }

////////////////////////////////////////////////////////////////////////////////
// Arbitrary polygon union, intersection, and difference (Greiner-Hormann)
////////////////////////////////////////////////////////////////////////////////
// Difference tested on KTH Challenge 2013 G; use others at your own risk
// runtime and memory usage scales on number of intersections, O(n^2 log n)
// degeneracies will fail! try moving degenerate points slightly (untested)
//! here a degenerate point means one that is on another point or an edge;
//! you could create separate polygons or combine points in any case
// usage:
// 1. create subject and clip Polygons with Polygon sp, cp;
// 2. add respective vertices to Polygons with poly.add(new Vt(x,y))
// 3. call punion/pintersection/pdifference for the desired operation,
//    i.e. punion(cp) for the union of sp and c;
//         pintersection(cp) for the intersection of sp and cp;
//         pdifference(cp) for the difference of sp and cp (sp-cp)
// 4. get points with Polygon::pts(), which returns a pol (i.e. vector<pt>)
//*!
// ported from Java version of https://github.com/helderco/univ-polyclip
// caveat: Polygon is comprised of a doubly linked list of Vt (vertices); memory
//         management is nearly non-existent so if you are running this code
//         multiple times in one program, and you are running out of memory, you
//         might want to delete all the Vt pointers in a Polygon and/or use a
//         destructor (see Polygon::pts() for iteration through vertices).
//*/
struct Vt; // vertex
struct Its; // intersection
struct Polygon;
 
struct Vt { ld x, y, a; Vt *n, *p, *nb; bool e, is, ch;
  Vt(ld X, ld Y) { x=X;y=Y; e=1; a=is=ch=0; }
  void sch() { ch=1; if (nb && !nb->ch) nb->sch(); }
  bool in(Polygon); };
 
Vt* is(ld x, ld y, ld a) { Vt* v=new Vt(x,y);v->a=a;v->is=1;v->e=0; return v; }
 
struct Its { ld x, y, us, uc; Its(Vt* s1, Vt* s2, Vt* c1, Vt* c2) {
  ld d=(c2->y-c1->y)*(s2->x-s1->x)-(c2->x-c1->x)*(s2->y-s1->y); if (!d) return;
  us=((c2->x-c1->x)*(s1->y-c1->y)-(c2->y-c1->y)*(s1->x-c1->x))/d;
  uc=((s2->x-s1->x)*(s1->y-c1->y)-(s2->y-s1->y)*(s1->x-c1->x))/d;
  if (test()) { x=s1->x+us*(s2->x-s1->x); y=s1->y+us*(s2->y-s1->y); } }
  bool test() { return 0 < us && us < 1 && 0 < uc && uc < 1; } };
 
struct Polygon { Vt* f; int vts; Polygon() { vts=0;f=0; }
  void add(Vt* v) { if (!f) { f=v; f->n=v; f->p=v; } else { Vt* n, *p; n=f;
    p=n->p; n->p=v; v->n=n; v->p=p; p->n=v; } vts++; }
  void ins(Vt* v, Vt* s, Vt* e) { Vt* p, *c=s; while (c!=e && c->a<v->a) c=c->n;
    v->n=c; p=c->p; v->p=p; p->n=v; c->p=v; vts++; }
  Vt* nxt(Vt* v) { Vt* c=v; while (c->is) c=c->n; return c; }
  pol pts() { pol r; Vt* v=f;
    for (int i=0;i<vts;i++) { r.push_back(pt(v->x,v->y)); v=v->n; } return r; }
  vector<Polygon> punion(Polygon p) { return cl(p, 0, 0); }
  vector<Polygon> pintersection(Polygon p) { return cl(p, 1, 1); }
  vector<Polygon> pdifference(Polygon p) { return cl(p, 0, 1); }
  //*!
  // you can use the cl() function directly instead of calling the wrappers
  // call           |  returns
  // A.cl(B, 0, 0)  |  A | B
  // A.cl(B, 1, 1)  |  A & B
  // A.cl(B, 0, 1)  |  A \ B
  // A.cl(B, 1, 0)  |  B \ A
  //*/
  vector<Polygon> cl(Polygon cp, bool s_e, bool c_e) { Vt* s=f, *c=cp.f;
    do { if (!s->is) { do { if (!c->is) {
      Its* i=new Its(s, nxt(s->n), c, cp.nxt(c->n));
      if (i->test()) { Vt* iS=is(i->x, i->y, i->us), *iC=is(i->x, i->y, i->uc);
        iS->nb=iC; iC->nb=iS; ins(iS,s,nxt(s->n)); cp.ins(iC,c,cp.nxt(c->n)); }
      delete i; } c=c->n; } while (c!=cp.f); } s=s->n; } while (s!=f);
    s=f; c=cp.f; s_e^=s->in(cp); c_e^=c->in(*this);
    do { if (s->is) { s->e=s_e; s_e=!s_e; } s=s->n; } while (s!=f);
    do { if (c->is) { c->e=c_e; c_e=!c_e; } c=c->n; } while (c!=cp.f);
    vector<Polygon> l; while (1) { Vt* v=f; do { if (v->is && !v->ch) break;
      v=v->n; } while (v!=f); if (v==f) break; Vt* c=f;
    do { if (c->is && !c->ch) break; c=c->n; } while (c!=f);
    Polygon p; p.add(new Vt(c->x, c->y)); do { c->sch(); if (c->e) do {c=c->n;
      p.add(new Vt(c->x, c->y)); } while (!c->is); else do { c=c->p;
      p.add(new Vt(c->x, c->y)); } while (!c->is); c=c->nb; } while (!c->ch);
      l.push_back(p); } if (!l.size()) l.push_back(*this); return l; } };
//! checks if vertex is inside polygon p
bool Vt::in(Polygon p) { int wn=0; Vt* q=p.f, *ify=new Vt(INF, this->y); Its* i;
  do { i=new Its(this, ify, q, p.nxt(q->n)); if (!q->is && i->test()) wn++;
  q=q->n; delete i; } while (q!=p.f); delete ify; return wn%2; }

int main(){
  ios::sync_with_stdio(0);
 
  int n, r; cin >> n >> r;
  vector<pii> coords;


  for(int i = 0; i < n; i++) {
    int xii, yii; cin >> xii >> yii; coords.push_back({xii, yii});
  }
  
  double maxArea = 0;
  int numPts = 100;

  for(double i = -0.5; i <= 0.5; i += 0.05) {
    for(double j = -0.5; j <= 0.5; j += 0.05) {
      Polygon sp = Polygon();

      for(int i = 0; i < n; i++) {
        sp.add(new Vt(coords[i].first, coords[i].second));
      }
      Polygon cp = Polygon();
      pt vec (0, r);
      pt center = centroid(sp.pts());
      pt tmpCenter = center + pt (i, j);

      for(int i = 0; i < numPts; i++) {
        cp.add(new Vt(vec.real() + tmpCenter.real(), vec.imag() + tmpCenter.imag()));
        vec = vec * (pt(cos(2*PI/numPts), sin(2*PI/numPts)));
      }

      vector<Polygon> ans = sp.pintersection(cp);

      pol outPol = ans[0].pts();

      maxArea = max(maxArea, area(outPol));
      cout << i << " " << j << " " << area(outPol) <<  endl;
    }
  }
  cout << fixed << setprecision(6) << maxArea << endl;
  
  return 0;
}