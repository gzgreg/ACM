#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	map<int, int> vals;

	int n; cin >> n;

	for(int i = 0; i < n; i++) {
		int curr; cin >> curr; vals[curr]++;
	}
	int total = 0;
	int workingTotal = 0;
	for(auto it = vals.begin(); it != vals.end(); it++) {
		int numReq = it->first;
		total += it-> second;
		if(total > numReq) {
			workingTotal = total;
		}
	}

	cout << workingTotal << endl;
	
	return 0;
}