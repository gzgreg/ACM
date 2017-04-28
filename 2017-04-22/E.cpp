#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int N; cin >> N;
	vector<int> vals;
	for(int i = 0; i < N; i++) {
		int curr; cin >> curr; vals.push_back(curr);
	}

	sort(vals.begin(), vals.end());

	vector<int> out (N, 0);
	int middle = (N + 1) / 2;
	for(int i = middle-1, j = 0; i >= 0; i--, j++) {
		out[2*j] = vals[i];
	}
	for(int i = middle, j = 0; i <= N; i++, j++) {
		out[2*j + 1] = vals[i];
	}

	for(int i = 0; i < N; i++) {
		cout << out[i] << " ";
	}
	cout << endl;
	
	return 0;
}