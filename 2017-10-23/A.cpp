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

	int n; string s, res;

	map<string, int> solved;

	map<string, int> wrong;

	cin >> n;
	while(n != -1) {
		cin >> s >> res;

		if(res[0] == 'r' && !solved.count(s)) {
			solved[s] = n + wrong[s] * 20;
		} else {
			wrong[s]++;
		}

		cin >> n;
	}

	int ans = solved.size();
	int t = 0;
	for(auto cur : solved) {
		t += cur.second;
	}

	cout << ans << " " << t << endl;
	
	return 0;
}