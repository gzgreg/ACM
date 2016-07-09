#include <math.h>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

map<int, long> memo;
string s;

long dp(int i){
	if(i >= s.size()){
		return 1;
	} else if(s[i] == '0'){
		return 0;
	} else if(i == s.size() - 1){
		return 1;
	} else if(memo.find(i) != memo.end()){
		return memo.at(i);
	}
	long retVal = dp(i+1);
	if((int)(s[i] - '0')*10 + (int)(s[i+1] - '0') <= 26){
		retVal += dp(i+2);
	}

	memo[i] = retVal;
	return retVal;
}

int main(){
	ios::sync_with_stdio(0);

	cin >> s;

	while(s != "0"){
		memo.clear();
		cout << dp(0) << endl;
		cin >> s;
	}

	return 0;
}