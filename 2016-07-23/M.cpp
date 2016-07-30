#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;
	long long a = 0, b = 0;

	for(int i = 0; i < n; i++) {
		long long ai, bi; cin >> ai >> bi;

		b = b == 0 ? bi : __gcd(b, bi);
		a = a == 0 ? ai : a / __gcd(a, ai) * ai;
	}

	long long reduce = __gcd(a, b);
	a /= reduce;
	b /= reduce;

	cout << a << " " << b << endl;
	
	return 0;
}