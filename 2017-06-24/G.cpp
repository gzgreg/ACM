#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000000007

ll egcd(ll a, ll b, ll& x, ll &y) {
  if (!b) {x = 1; y = 0; return a;}//to ensure d>=0: x=sgn(a);y=0;return abs(a);
  ll d = egcd(b, a%b, y, x); y -= x * (a/b); return d; }

struct Matrix {
	ll a, b, c, d;
};

Matrix operator*(Matrix a, Matrix b) {
	Matrix out;
	out.a = a.a*b.a + a.b*b.c;
	out.b = a.a*b.b + a.b*b.d;
	out.c = a.c*b.a + a.d*b.c;
	out.d = a.c*b.b + a.d*b.d;
	return out;
}

Matrix operator%(Matrix a, int b) {
	a.a %= b;
	a.b %= b;
	a.c %= b;
	a.d %= b;
	return a;
}

ostream& operator<<(ostream& o, Matrix a) {
	o << a.a << " " << a.b << " " << a.c << " " << a.d;
	return o;
}

Matrix mod_pow(Matrix base, int exp) {
	Matrix val = {1, 0, 0, 1};
	base = base %MOD;
	while(exp > 0) {
		if(exp % 2 == 1) {
			Matrix tmp = val;
			val = val * base;
			val = val % MOD;
		}
		exp = exp / 2;
		base = base * base;
		base  = base % MOD;
	}

	return val;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	Matrix powMat = {1, 1, 1, 0};

	int T; cin >> T;
	for(int id = 1; id <= T; id++) {
		cout << "Case " << id << ": ";
		int L, R, K; cin >> L >> R >> K;
		Matrix out = mod_pow(powMat, K);
		cout << out << endl;
		Matrix inv = {0, 0, 0, 0};
		Matrix tmp = out;
		tmp.a -= 1;
		tmp.d -= 1;
		inv.a = -tmp.d;
		inv.b = tmp.b;
		inv.c = tmp.c;
		inv.d = -tmp.a;

		cout << R/K << " " << (L + K-1) / K << endl;
		Matrix a = mod_pow(out, R/K);
		Matrix b = mod_pow(out, (L + K-1) / K);
		cout << a << " " << b << endl;
		Matrix numer;
		numer.a = a.a-b.a;
		numer.b = a.b-b.b;
		numer.c = a.c-b.c;
		numer.d = a.d-b.d;
		cout << inv << endl;
		Matrix ans = inv*numer;
		ans = ans % MOD;
		cout << ans << endl;
	}
	
	return 0;
}