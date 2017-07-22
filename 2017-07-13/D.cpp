#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	int n, k, p; cin >> n >> k >> p;
	
	vector<int> pos, key;
	for(int i = 0; i < n; i++) {
		int curr; cin >> curr; pos.push_back(curr);
	}
	for(int i = 0; i < k; i++) {
		int curr; cin >> curr; key.push_back(curr);
	}

	sort(pos.begin(), pos.end());
	sort(key.begin(), key.end());

	int bestDist = 2e9 + 1;
	for(int guess = 0; guess <= k-n; guess++) {
		int maxDist = 0;
		for(int i = guess, j = 0; j < n; i++, j++) {
			int dist1;
			if((key[i] > p && key[i] < pos[j])
				|| (key[i] < p && key[i] > pos[j])) {
				dist1 = abs(pos[j] - p);
			} else {
				dist1 = abs(pos[j] - key[i]) + abs(key[i] - p);
			}
			maxDist = max(dist1, maxDist);
		}
		bestDist = min(maxDist, bestDist);
	}

	cout << bestDist << endl;

	return 0;
}