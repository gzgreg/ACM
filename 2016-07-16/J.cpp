#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	int T; cin >> T;
	while(T--) {
		int N; cin >> N;
		int limit = sqrt(N);
		bool found = false;
		for(int i = limit; i >= 1; i--) {
			if(N % i == 0) {
				//i is a factor: try writing N as a sum of
				//i odd numbers near N/i
				int dist = N/i;
				if(dist % 2 == 0 && i % 2 == 1
					|| dist % 2 == 1 && i % 2 == 0) {
					//cannot be written as a sum of odd numbers
					continue;
				}
				int mod = dist % 2;
				int left, right;
				if(mod == 1) {
					left = ((dist - i) + 1) / 2;
					right = ((i + dist) + 1) / 2;
				} else {
					left = (dist - i) / 2;
					right = (i + dist) / 2;
				}
				if(left < 0) continue;
				cout << left << " " << right << endl;
				found = true;
				break;
			}
		}

		if(!found) cout << "IMPOSSIBLE" << endl;
	}
	
	return 0;
}