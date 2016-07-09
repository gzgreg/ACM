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
	int currSwap = -1;
	int ops = 0;
	vector<pii> swaps;
	for(int i = 1; i <= n; i++){
		int curr; cin >> curr;
		if(curr == i){
			if(currSwap == -1){
				currSwap = i;
			} else {
				ops++;
				swaps.push_back({currSwap, i});
				currSwap = -1;
			}
		}
	}

	if(currSwap != -1){
		if(currSwap == 1){
			swaps.push_back({currSwap, 2});
		} else {
			swaps.push_back({currSwap, 1});
		}
		ops++;
	}
	cout << ops << endl;
	
	for(int i = 0; i < swaps.size(); i++){
		cout << swaps[i].first << " " << swaps[i].second << endl;
	}

	return 0;
}