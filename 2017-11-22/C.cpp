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

	int n; cin >> n;
	bitset<200001> t;

	int ans = 1;
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur;
		t[cur] = true;
	}

	cout << n - t.count() + 1 << endl;
	
	return 0;
}