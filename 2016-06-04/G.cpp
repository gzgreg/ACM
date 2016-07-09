#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int a, b; cin >> a >> b;

	int a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2;

	int a3 = a1 + a2, b3 = max(b1, b2);
	int a4 = a1 + b2, b4 = max(a2, b1);
	int a5 = b1 + b2, b5 = max(a1, a2);
	int a6 = a2 + b1, b6 = max(a1, b2);
	if((a3 <= a && b3 <= b) || (a3 <= b && b3 <= a)
		|| (a4 <= a && b4 <= b) || (a4 <= b && b4 <= a)
		|| (a5 <= a && b5 <= b) || (a5 <= b && b5 <= a)
		|| (a6 <= a && b6 <= b) || (a6 <= b && b6 <= a)){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}