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

	int m; cin >> m;

	vector<pii> B; vector<int> A;

	for(int i = 0; i < m; i++) {
		int cur; cin >> cur; A.push_back(cur);
	}

	for(int i = 0; i < m; i++) {
		int cur; cin >> cur; B.push_back({cur, i});
	}

	sort(A.begin(), A.end());
	reverse(A.begin(), A.end());
	sort(B.begin(), B.end());

	vector<int> ans(m);
	for(int i = 0; i < m; i++) {
		ans[B[i].second] = A[i];
	}

	for(int i = 0; i < m; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}