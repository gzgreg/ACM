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

	int K; cin >> K;

	vector<int> cycleSizes;
	int totSize = 0;
	while(K > 0) {
		int i = ((int) sqrt(2*K));
		while(i*(i-1)/2 <= K) {
			i++;
		}
		i--;

		cycleSizes.push_back(i);
		totSize += i;
		K -= i*(i-1) / 2;
	}

	cout << totSize << " " << totSize + cycleSizes.size()-1 << endl;
	int curStart = 1;
	for(int cur : cycleSizes) {
		for(int i = 0; i < cur; i++) {
			cout << i + curStart << " " << ((i+1) % cur) + curStart << endl;
		}
		if(curStart != 1) cout << curStart-1 << " " << curStart << endl;
		curStart += cur;
	}
	
	return 0;
}