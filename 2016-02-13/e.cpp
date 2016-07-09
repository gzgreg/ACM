#include <math.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int memo[1000][1000];
vector<vector<int> > mat;
int N, M;

int dp(int N, int M, int i, int j){
	if(i >= N || j >= M || mat[i][j] == 0){
		return 0;
	} else if(memo[i][j] != -1){
		return memo[i][j];
	}

	int retVal = min(min(dp(N, M, i+1, j), dp(N, M, i, j+1)), dp(N, M, i+1, j+1)) + 1;
	memo[i][j] = retVal;
	return retVal;
}

int main(){
	ios::sync_with_stdio(0);

	cin >> N >> M;
	while(N != 0){
		mat.clear();
		memset(memo, -1, sizeof memo);
		for(int i = 0; i < N; i++){
			vector<int> curr;
			for(int j = 0; j < M; j++){
				int currVal; cin >> currVal;
				curr.push_back(currVal);
			}
			mat.push_back(curr);
		}
		int max = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(dp(N, M, i, j) > max){
					max = dp(N, M, i, j);
				}
			}
		}

		cout << max << endl;

		cin >> N >> M;
	}

	return 0;
}