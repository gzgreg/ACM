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
		int N, K; cin >> N >> K;

		priority_queue<int> pq;

		pq.push(N);

		for(int i = 0; i < K-1; i++) {
			int curr = pq.top(); pq.pop();
			if(curr == 1) continue;
			if(curr % 2) {
				pq.push(curr/2);
				pq.push(curr/2);
			} else {
				pq.push(curr/2);
				if(curr > 2) pq.push(curr/2 - 1);
			}
		}
		int gap = pq.top();

		cout << "Case #" << id << ": ";
		if(gap % 2) {
			cout << gap/2 << " " << gap/2 << endl;
		} else {
			cout << gap/2 << " " << gap/2 - 1 << endl;
		}
	}
	
	return 0;
}