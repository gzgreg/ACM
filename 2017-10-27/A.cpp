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

	vector<pii> doctors;
	for(int i = 0; i < n; i++) {
		int si, di; cin >> si >> di; doctors.push_back({si, di});
	}

	int curDay = 0;

	for(int i = 0; i < n; i++) {
		int si = doctors[i].first;
		int di = doctors[i].second;
		if(curDay < si) {
			curDay = si;
		} else {
			curDay = ((curDay - si) / di) * di + di + si;
		}
	}

	cout << curDay << endl;
	
	return 0;
}