#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	long long n, k; cin >> n >> k;
	long long swaps = min(n / 2, k);
	long long noswap = n - 2*swaps;

	cout << (n*(n-1))/2 - (noswap*(noswap-1)/2) << endl;
	
	return 0;
}