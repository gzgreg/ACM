#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define PI 3.141592653L
int n;
// vector<complex<double>> FFT(vector<complex<double>> vals, bool inverse) {
// 	if(vals.size() == 1) return vals;
// 	complex<double> root = polar(1.0, 2.0 * PI / vals.size());
// 	if(inverse) root = conj(root);
// 	vector<complex<double>> even, odd;
// 	for(int i = 0; i < vals.size(); i++) {
// 		if(i % 2) {
// 			even.push_back(vals[i]);
// 		} else {
// 			odd.push_back(vals[i]);
// 		}
// 	}
//     vector<complex<double>> F_even = FFT(even, inverse);
//     vector<complex<double>> F_odd = FFT(odd, inverse);
//     vector<complex<double>> F (vals.size(), 0);
    
//     complex<double> x (1, 0);
//     for (int j=0; j < vals.size()/2; ++j) {
//     	F[j] = F_even[j] + x*F_odd[j];
//      	F[j+vals.size()/2] = F_even[j] - x*F_odd[j];
//     	x = x * root;
// 	}
// 	return F;
// }
typedef complex<ld> Complex;
inline int rev_incr(int a, int n) { int msk = n/2, cnt=0;
  while ( a&msk ) { cnt++; a<<=1; }
  a &= msk-1; a |= msk;
  while ( cnt-- ) a >>= 1;
  return a; }
// Compute in V the discrete fourier transform of v
// dir=1: forward transform, evaluates polynomial at complex roots of unity
// dir=-1: inverse transform, interpolates point-value form to coefficients
vector<Complex> FFT(vector<Complex> v, int dir=1) {
	cout << v.size() << endl;
  Complex wm,w,u,t; int l = v.size(); vector<Complex> V(l);
  for (int k=0,a=0; k<l; ++k, a=rev_incr(a,l))
    V[a] = v[k] / ld(dir>0 ? 1 : l);
  for (int m=2; m<=l; m<<=1) {
    wm = polar( (ld)1, dir*2*PI/m );
    for (int k=0; k<l; k+=m) {
      w = 1;
      for (int j=0; j<m/2; ++j, w*=wm) {
        u = V[k + j];
        t = w * V[k + j + m/2];
        V[k + j] = u + t;
        V[k + j + m/2 % n] = u - t;
      } } } return V; }
//! See problem 30-6 in CLRS for more details on the integer FFT
//! hints for integer version:
//! 440564289 and 1713844692 are inverses and 2^27th roots of 1 mod p=(15<<27)+1
//! Precompute inverses for integer FFT, otherwise it will be very slow.
// Multiply two polynomials sum_i a[i]x^i and sum_i b[i]x^i
vector<ld> convolution(vector<ld> a, vector<ld> b) {
  int sz = a.size()+b.size()-1;
  int l  = min(1<<int(ceil(log2(sz))), 1<<int(ceil(log2(n))));
  vector<Complex> av(l,0), bv(l,0), cv;
  for (int i=0; i<a.size(); i++) av[i] = a[i];
  for (int i=0; i<b.size(); i++) bv[i] = b[i];
  cv = FFT(bv); bv = FFT(av);
  for (int i=0; i<l; i++) av[i] = bv[i]*cv[i];
  cv = FFT(av, -1);
  // cv is now the convolution of a and b: cv[k] = sum_(i+j=k) a[i]*b[j]
  vector<ld> c(sz);
  for (int i=0; i<sz; i++)
    c[i] = cv[i].real(); // if result should be int, use int(cv[i].real()+0.5)
  return c; }
int main(){
	ios::sync_with_stdio(0);

	cin >> n;

	vector<ll> sqr (n, 0);

	for(int i = 1; i < n; i++) {
		sqr[i*i % n]++;
	}

	//triples where a = b
	ll ans = 0;
	vector<ld> orig (n, 0);
	for(int i = 0; i < n; i++) {
		ans += sqr[i] * sqr[2*i % n];
		orig[i] = sqr[i];
	}

	//all triples, double-counted except a = b

	vector<ld> result = convolution(orig, orig);
	// for(int i : orig) {
	// 	cout << i << " ";
	// }
	// cout << endl;
	// for(ld i : result) {
	// 	cout << (int) i << " ";
	// }
	// cout << endl;
	for(int i = 0; i < result.size(); i++) {
		ans += ((ll) (result[i] + 0.5)) * sqr[i % n];
		// cout << ans << " " << (int) (result[i] + 0.5) << " " << sqr[i%n] << endl;
	}
	// cout << endl;

	cout << ans / 2 << endl;
	
	return 0;
}