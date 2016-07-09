#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

vector<long long> tStep;
long long n, d, c;
vector<vector<long long>> memo;

int main(){
	ios::sync_with_stdio(0);

	cin >> n >> d >> c;

	long long last; cin >> last;
	for(long long i = 0; i < n - 1; i++) {
		long long curr; cin >> curr; tStep.push_back(curr-last); last = curr;
	}

	memo = vector<vector<long long>> (n+1, vector<long long>(n+1, -1));

	// long long numOrders = 1;
	// long long currCost = 0;
	// long long totalCost = 0;
	// for(long long i = 0; i < tStep.size(); i++) {
	// 	long long costIfDelay = tStep[i]*c*numOrders;
	// 	long long costNoDelay = d;
	// 	if(costIfDelay < costNoDelay) {
	// 		currCost += costIfDelay;
	// 		numOrders++;
	// 	} else {
	// 		totalCost += currCost + d;
	// 		currCost = 0;
	// 		numOrders = 1;
	// 	}
	// }
	// totalCost += currCost + d;
	//cout << totalCost << endl;
	memo[0][0] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			if(i != n-1) {
				if(memo[i+1][j+1] == -1) {
					memo[i+1][j+1] = memo[i][j] + tStep[i]*c*(j+1);
				} else {
					memo[i+1][j+1] = min(memo[i+1][j+1], memo[i][j] + tStep[i]*c*(j+1));
				}
			}
			
			if(memo[i+1][0] == -1) {
				memo[i+1][0] = memo[i][j] + d;
			} else {
				memo[i+1][0] = min(memo[i+1][0], memo[i][j] + d);
			}
		}
	}
	cout << memo[n][0] << endl;
	
	return 0;
}