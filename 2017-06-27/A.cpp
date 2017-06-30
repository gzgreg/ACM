#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	int c, v0, v1, a, l; cin >> c >> v0 >> v1 >> a >> l;

	int maxPage = 0;
	int days = 0;
	while(maxPage < c) {
		maxPage = max(0, maxPage - l);
		maxPage += min(v1, v0 + days * a);
		days++;
	}

	cout << days << endl;
	
	return 0;
}