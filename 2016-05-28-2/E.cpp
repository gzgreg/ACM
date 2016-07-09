#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	long long N, B, H, W; cin >> N >> B >> H >> W;

	long long minCost = 100000000000;

	for(int i = 0; i < H; i++){
		long long p; cin >> p;
		for(int j = 0; j < W; j++){
			long long val; cin >> val;
			if(val >= N){
				minCost = min(minCost, p*N);
			}
		}
	}
	if(minCost <= B){
		cout << minCost << endl;
	} else {
		cout << "stay home" << endl;
	}
	
	return 0;
}