#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	long long n, m; cin >> n >> m;

	long long numSides = (n+1) * m + n*(m+1);

	cout << (numSides - abs(n-m)) / 2 << endl;
	
	return 0;
}