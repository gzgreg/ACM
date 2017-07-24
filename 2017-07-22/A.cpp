#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	int n, a, b; cin >> n >> a >> b;
	vector<int> times;
	for(int i = 0; i < n; i++) {
		int curr; cin >> curr; times.push_back(curr);
	}

	queue<int> vals;
	int j = 0;
	for(int i = 0; i <= 3000; i++) {
		if(times[j] == i) {
			vals.push(i);
			j++;
		}
		if(vals.size() >= a || i - vals.front() >= b) {
			int numToRead = (vals.size() + 1) / 2;
			for(int k = 0; k < numToRead; k++) {
				cout << i << " ";
				vals.pop();
			}
		}
	}
	
	return 0;
}