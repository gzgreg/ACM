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
	vector<int> a, b;
	for(int i = 0; i < n; i++) {
		int curr; cin >> curr; a.push_back(curr);
	}
	for(int i = 0; i < n; i++) {
		int curr; cin >> curr; b.push_back(curr);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int aWins = 0, bWins = 0;

	int j = 0;
	for(int i = 0; i < n && j < n; i++) {
		while(a[i] < b[j] && j < n) {
			j++;
		}
		if(j == n) break;
		aWins++;
		j++;
	}

	j = 0;
	for(int i = 0; i < n && j < n; i++) {
		while(b[i] < a[j] && j < n) {
			j++;
		}
		if(j == n) break;
		bWins++;
		j++;
	}
	if(aWins > n/2 && bWins > n/2) {
		cout << "Both" << endl;
	} else if(aWins > n/2) {
		cout << "First" << endl;
	} else if(bWins > n/2) {
		cout << "Second" << endl;
	} else {
		cout << "None" << endl;
	}
	
	return 0;
}