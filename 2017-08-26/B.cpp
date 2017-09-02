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
	
	string s; cin >> s;
	vector<int> vals(26);

	for(char i : s) {
		vals[i - 'a']++;
	}

	double ans = 0;
	for(int i : vals) {
		ans += (double) i * i / s.size();
	}

	cout << fixed << setprecision(10) << ans << endl;

	return 0;
}