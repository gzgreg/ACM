#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

vector<int> trees;
vector<vector<double>> memo;

int N, L, W; 
double posDist;

double dp(int l, int r){
	int treeNum = N - l - r;
	if(l == 0 && r == 0){
		return 0;
	} else if(memo[l][r] > 0){
		return memo[l][r];
	} 
	else if(r == 0){
		double ans = abs(trees[treeNum]-posDist*(N/2 - l)) + dp(l-1, r);
		memo[l][r] = ans;
		return ans;
	} else if(l == 0){
		double ans = sqrt((trees[treeNum]-posDist*(N/2 - r))*(trees[treeNum]-posDist*(N/2 - r))+W*W) + dp(l, r-1);
		memo[l][r] = ans;
		return ans;
	} else {
		double ans = min(abs(trees[treeNum]-posDist*(N/2 - l)) + dp(l-1, r), sqrt((trees[treeNum]-posDist*(N/2 - r))*(trees[treeNum]-posDist*(N/2 - r))+W*W) + dp(l, r-1));
		memo[l][r] = ans;
		return ans;
	}
}

int main(){
	ios::sync_with_stdio(0);

	cin >> N >> L >> W;

	for(int i = 0; i < N; i++){
		int curr; cin >> curr; trees.push_back(curr);
	}
	memo = vector<vector<double>> (N/2+1, vector<double> (N/2+1, -1));
	sort(trees.begin(), trees.end());

	posDist = (double) L / (N/2-1);
	double totalDist = dp(N/2, N/2);

	cout << fixed << setprecision(10) << totalDist << endl;
	
	return 0;
}