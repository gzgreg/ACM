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

	int n, k; cin >> n >> k;

	vector<int> groups;
	for(int i = 0; i < k; i++) {
		int cur; cin >> cur; groups.push_back(cur);
	}

	int fours = n, twos = 2 * n;

	for(int i = 0; i < k; i++) {
		while(groups[i] >= 4 && fours > 0) {
			fours--;
			groups[i] -= 4;
		}
	}

	int numPairs = 0;
	for(int i = 0; i < k; i++) {
		while(groups[i] >= 2 && twos > 0) {
			twos--;
			groups[i] -= 2;
		}
	}

	for(int i = 0; i < k; i++) {
		while(groups[i] >= 2 && fours > 0) {
			fours--;
			twos++;
			groups[i] -= 2;
		}
	}
	
	twos += 2 * fours;
	for(int i = 0; i < k; i++) {
		while(groups[i] && twos > 0) {
			groups[i]--;
			twos--;
		}
	}

	for(int i = 0; i < k; i++) {
		if(groups[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	return 0;

	
	return 0;
}