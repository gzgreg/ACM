#include <bits/stdtr1c++.h>

using namespace std;

vector<int> dfs(int, int, int, vector<int>);
int n, t; 
string s1, s2;
bool diff[10000];

int main(){
	cin >> n >> t;
	cin >> s1 >> s2;

	for(int i = 0; i < n; i++){
		diff[i] = (s1[i] == s2[i]);
	}

	vector<int> temp;
	vector<int> result = dfs(0, t, t, temp);

	return 0;
}

vector<int> dfs(int idx, int diff1, int diff2, vector<int> currChg){
	if(idx == n - 1){
		vector<int> newVec = currChg; 
		if(diff[idx] && diff1 == 1 && diff2 == 1){
			newVec.push_back(1);
		} else if(diff[idx] && diff1 == 0 && diff2 == 0){
			newVec.push_back(0);
		} else if(!diff[idx] && diff1 == 1 && diff2 == 0){
			newVec.push_back(1);
		} else if(!diff[idx] && diff1 == 0 && diff2 == 1){
			newVec.push_back(2);
		} else {
			throw;
		}
	}
}