#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ld> memo(1000000, -1);
string s;

int main(){
	ios::sync_with_stdio(0);
	freopen("foreign.in", "r", stdin);
	freopen("foreign.out", "w", stdout);

	cin >> s;
	memo[s.size()] = 0;
	ld totalMemo = 0;
	ll totalC = 0;
	for(int idx = s.size() - 1; idx >= 0; idx--) {
		bool flip = (s[idx] == 'W');
		ld expected = totalMemo;
		totalC += (s.size() - idx) * (!flip);
		expected += flip ? totalC : ((ll) s.size()-idx) * (s.size()-idx + 1) / 2 - totalC;
		expected = expected / (s.size() - idx);
		memo[idx] = expected;
		totalMemo += memo[idx];
	}

	cout << fixed << setprecision(10) << memo[0] << endl;
	
	return 0;
}