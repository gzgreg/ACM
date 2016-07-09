#include <math.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int memo[100][100];
vector<vector<int> > tri;
int N;

int dp(int i, int j){
	if(i == tri.size() - 1){
		return tri[i][j];
	} else if(memo[i][j] != -1){
		return memo[i][j];
	}

	int retVal = max(dp(i+1, j), dp(i+1, j+1)) + tri[i][j];
	memo[i][j] = retVal;
	return retVal;
}

int main(){
	ios::sync_with_stdio(0);

	cin >> N;

	for(int i = 0; i < N; i++){
		vector<int> curr;
		for(int j = 0; j <= i; j++){
			int currVal; cin >> currVal;
			curr.push_back(currVal);
		}
		tri.push_back(curr);
	}
	memset(memo, -1, sizeof memo);

	cout << dp(0, 0) << endl;

	return 0;
}