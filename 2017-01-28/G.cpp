#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	while(T--) {
		vector<pii> points;

		int W, N; cin >> W >> N;

		for(int i = 0; i < N; i++) {
			int xi, wi; cin >> xi >> wi; points.push_back({xi, wi});
		}

		int currWeight = 0;
		int dist = 0;
		for(int i = 0; i < N; i++) {
			if(currWeight + points[i].second > W) {
				dist += 2 * points[i].first;
				currWeight = points[i].second;
			} else if (currWeight + points[i].second == W) {
				dist += 2 * points[i].first;
				currWeight = 0;
			} else {
				currWeight += points[i].second;
			}
		}

		if(currWeight != 0) dist += 2 * points[N-1].first;
		cout << dist << endl;
	}
	
	return 0;
}