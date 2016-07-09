#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	long long n, a, b, c, d; cin >> n >> a >> b >> c >> d;

	long long minSum = min(min(min(a+b, a+c), b+d), c+d);
	long long maxSum = max(max(max(a+b, a+c), b+d), c+d);

	long long diff = maxSum - minSum;

	long long ops = max(n-diff, (long long)0);

	cout << ops*n << endl;
	
	return 0;
}