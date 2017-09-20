#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	double p, q; cin >> p >> q;

	double probpgivenHeads = p / 100 * 0.5 / (p / 200 + q / 200);
	double probqgivenHeads = q / 100 * 0.5 / (p / 200 + q / 200);

	cout << fixed << setprecision(10) << probpgivenHeads*p/100 + probqgivenHeads*q/100 << endl;
	
	return 0;
}