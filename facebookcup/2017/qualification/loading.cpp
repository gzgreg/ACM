#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	for(int id = 1; id <= T; id++) {

		int N; cin >> N;
		vector<int> items;
		for(int i = 0; i < N; i++) {
			int curr; cin >> curr; items.push_back(curr);
		}

		sort(items.begin(), items.end());
		reverse(items.begin(), items.end());

		int numTrips = 0;
		while(N > 0) {
			int currItem = items[numTrips];
			if(N * currItem >= 50) {
				N -= (50 / currItem) + (50 % currItem != 0);
				numTrips++;
			} else {
				N = 0;
			}
		}
		cout << "Case #" << id << ": " << numTrips << endl;
	}
	
	return 0;
}