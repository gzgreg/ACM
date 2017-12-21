#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef complex<ll> pt;

ld cp(const pt& a, const pt& b) { return imag(conj(a)*b); }

namespace std {
template<class T>inline bool operator<(const complex<T>& a,const complex<T>& b){
  return a.real()<b.real() || (a.real() == b.real() && a.imag()<b.imag()); } };

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;

	vector<pt> pts;
	for(int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		pts.push_back({x, y});
	}
	if(N <= 2) {
		cout << N-1 << endl;
		return 0;
	}
	for(int i = 0; i < N; i++) {
		pt side1 = pts[(i+2) % N] - pts[(i+1) % N];
		pt side2 = pts[i] - pts[(i+1) % N];
		//cout << side1 << " " << side2 << endl;
		if(cp(side1, side2) < 0) {
			cout << "INFINITY" << endl;
			return 0;
		}
	}
	set<pt> slopes;
	for(int i = 0; i < N; i++) {
		pt side = pts[(i+1) % N] - pts[i];

		ll diff = __gcd(side.real(), side.imag());
		side /= diff;
		if(side.real() < 0) side *= -1;
		if(side.real() == 0) {
			if(side.imag() < 0) side *= -1;
		}

		slopes.insert(side);
	}

	cout << slopes.size() << endl;
	
	return 0;
}