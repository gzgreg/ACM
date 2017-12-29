#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll h = 0;
	ll b = 84;
	ll c = b;
	b *= 100;
	b += 100000;
	c = b;
	c += 17000;
	asdf2:
	ll f = 1;
	ll d = 2;

	asdf:
	ll e = 2;

	ll g = d;
	if(b % d == 0 && b / d != 1) {
		f = 0;
	}

	d += 1;
	g = d;
	g -= b;
	if(g != 0) {
		goto asdf;
	}
	if(f == 0) {
		h++;
	}
	g = b - c;
	if(g != 0) {
		b += 17;
		goto asdf2;
	}

	cout << h << endl;

	return 0;
}