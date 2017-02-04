#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, T; 
vector<int> d;

int solve(int K) {
	priority_queue<int, vector<int>, greater<int>> evt;

	for(int i = 0; i < K; i++) {
		evt.push(d[i]);
	}

	for(int i = K; i < N; i++) {
		int curr = evt.top(); evt.pop();
		evt.push(d[i] + curr);
	}

	while(evt.size() > 1) {
		evt.pop();
	}

	return evt.top();
}

int main(){
	ios::sync_with_stdio(0);

	cin >> N >> T;
	for(int i = 0; i < N; i++) {
		int curr; cin >> curr; d.push_back(curr);
	}
	int l=1, r=N;

	while(l <= r) {
		int mid = l + (r - l) / 2;
		if(solve(mid) <= T) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	cout << l << endl;
	
	return 0;
}