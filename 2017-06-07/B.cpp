#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

	vector<int> copy(a);

	int numDiffs = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] != b[i]) {
			numDiffs++;
		}
	}
	set<int> unseen;
	set<int> seen;
	int dup;
	for(int j = 1; j <= n; j++) {
		unseen.insert(j);
	}
	for(int j = 0; j < n; j++) {
		unseen.erase(a[j]);
		if(seen.count(a[j])) {
			dup = a[j];
		}
		seen.insert(a[j]);
	}
	if(numDiffs == 1) {
		for(int i = 0; i < n; i++) {
			if(a[i] != b[i]) {
				copy[i] = *(unseen.begin());
			}
		}
		for(int i = 0; i < n; i++) {
			cout << copy[i] << " ";
		}
		cout << endl;
	} else {
		for(int i = 0; i < n; i++) {
			if(a[i] != b[i] && b[i] == *(unseen.begin()) && a[i] == dup) {
				copy[i] = b[i];
				break;
			}
		}
		for(int i = 0; i < n; i++) {
			cout << copy[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}