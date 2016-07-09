#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <string.h>
#include <map>
#include <list>

using namespace std;

bool solve(int, int, bool);

int dp[501][501][2] = {-1};

int main(){
	int N; cin >> N;
	memset(dp, -1, sizeof dp);
	for(int i = 0; i < N; i++){
		int B, D; cin >> B >> D;
		string s; cin >> s;
		bool hStart = s == "Harry" ? true : false;
		bool result = solve(B, D, hStart);

		cout << s << " ";
		cout << (result ? "can win" : "cannot win") << endl;
	}
	return 0;
}

bool solve(int B, int D, bool hStart){
	if((hStart && D == 1) || (!hStart && B == 1)){
		return false;
	} else if((!hStart && D == 1) || (hStart && B == 1)){
		return true;
	} else if(dp[B][D][hStart] != -1){
		return hStart ? dp[B][D][hStart] : !dp[B][D][hStart];
	} else {
		bool winnable = false;
		if(hStart){
			for(int i = 1; i < D; i++){
				if(!solve(B, i, !hStart) && !solve(B, D-i, !hStart)){
					winnable = true;
				}
			}
		} else {
			for(int i = 1; i < B; i++){
				if(!solve(i, D, !hStart) && !solve(B - i, D, !hStart)){
					winnable = true;
				}
			}
		}
		dp[B][D][hStart] = hStart ? winnable : !winnable;
		return winnable;
	}
}