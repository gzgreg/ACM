#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);

	vector<int> x, y;
	for(int i = 0; i < 4; i++) {
		int a; cin >> a; x.push_back(a);
		cin >> a; y.push_back(a);
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	int minLength = max(x[3] - x[0], y[3] - y[0]);

	cout << minLength * minLength << endl;
	return 0;
}