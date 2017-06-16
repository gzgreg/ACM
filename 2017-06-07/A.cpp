#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int n, k; cin >> n >> k;
	vector<int> one, two;
	for(int i = 0; i < n; i++) {
		int curr; cin >> curr; one.push_back(curr);
	}
	for(int i = 0; i < k; i++) {
		int curr; cin >> curr; two.push_back(curr);
	}
	if(k > 1) {
		cout << "Yes" << endl;
		return 0;
	}

	for(int i = 0; i < n; i++) {
		if(one[i] == 0) {
			one[i] = two[0];
			break;
		}
	}

	vector<int> copy (one);
	sort(copy.begin(), copy.end());
	for(int i = 0; i < n; i++) {
		if(copy[i] != one[i]) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	
	return 0;
}