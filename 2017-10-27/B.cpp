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

	ll n, k; cin >> n >> k;
	vector<int> power(n);
	for(int i = 0; i < n; i++) {
		cin >> power[i];
	}

	if(k >= n) {
		cout << n << endl;
		return 0;
	}

	queue<int> line;

	for(int i = 0; i < n; i++) {
		line.push(power[i]);
	}

	int numWins = 0;
	int curWin = line.front(); line.pop();

	while(numWins < k) {
		int challenger = line.front(); line.pop();
		if(curWin > challenger) {
			line.push(challenger);
			numWins++;
		} else {
			numWins = 1;
			line.push(curWin);
			curWin = challenger;
		}
	}

	cout << curWin << endl;
	
	return 0;
}