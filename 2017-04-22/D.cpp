#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int N; cin >> N;

	vector<int> l1, l2;
	for(int i = 0; i < N; i++) {
		int curr; cin >> curr; l1.push_back(curr);
	}
	for(int i = 0; i < N; i++) {
		int curr; cin >> curr; l2.push_back(curr);
	}

	int best = -1;
	int tot = 0;
	for(int i = 0; i < N; i++) {
		tot += l1[i];
		tot -= l2[i];
		if(tot == 0) best = i;
	}

	cout << best+1 << endl;
	
	return 0;
}