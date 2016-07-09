#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	
	int n; cin >> n;

	vector<int> cumsum;

	long long total = 0;
	map<long long, int> seen; seen[0] = -1;
	int minDist = 10000000;
	int minIdx = -1;

	for(int i = 0; i < n; i++) {
		int curr; cin >> curr; total += curr;
		if(seen.find(total) != seen.end()) {
			if(minDist > i - seen[total]) {
				minDist = i - seen[total];
				minIdx = seen[total] + 2;
			}
		}
		seen[total] = i;
	}

	cout << minIdx;
	if(minIdx != -1) {
		cout << " " << minDist << endl;
	}

	return 0;
}