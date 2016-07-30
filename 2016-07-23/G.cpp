#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	
	int N; cin >> N;
	map<int, int> count;
	int maxCount = 0;
	for(int i = 0; i < N; i++) {
		int curr; cin >> curr;
		count[curr]++;
		if(count[curr] > maxCount) maxCount = count[curr];
	}

	cout << maxCount << endl;
	return 0;
}