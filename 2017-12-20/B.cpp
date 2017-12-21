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

	int N; cin >> N;
	vector<pii> vals;
	for(int i = 0; i < N-1; i++) {
		int ai, bi; cin >> ai >> bi; vals.push_back({ai, bi});
	}

	ld ans = 0;
	for(int i = 0; i < N-1; i++) {
		ld curProb = 0;
		for(int j = 1; j <= vals[i].second; j++) {
			curProb += 1;
			curProb *= ((ld) j)/(vals[i].first + j);
		}
		cout << curProb << endl;
		ans += (i+1) * curProb;
	}
	ans += N-1;
	
	cout << fixed << setprecision(10) << ans << endl;

	return 0;
}