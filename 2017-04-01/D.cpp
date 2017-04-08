#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> ledges;
int n, R, T; 

bool possible(int s) {
	int currT = 0, currLedge = 0;
	for(int i = 0; i <= n; i++) {
		if(ledges[i] > ledges[currLedge] + s) {
			currT += ledges[i-1] - ledges[currLedge];
			currT += R;
			currLedge = i-1;
		}
	}
	currT += ledges[n] - ledges[currLedge];

	return currT <= T;
}

int main(){
	ios::sync_with_stdio(0);

	cin >> n >> R >> T;
	int minVal = 0;
	ledges.push_back(0);
	for(int i = 0; i < n; i++) {
		int curr; cin >> curr; ledges.push_back(curr);
		minVal = max(minVal, ledges[i+1] - ledges[i]);
	}

	int l = minVal, r = 1e9;

	while(l < r) {
		int mid = (l + r) / 2;

		if(possible(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	
	if(!possible(l)) l++;

	cout << l << endl;

	return 0;
}