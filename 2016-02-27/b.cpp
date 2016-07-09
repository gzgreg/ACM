#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

vector<vector<long long>> memo;
vector<long long> fact (15000, 0);
vector<long long> invFact (15000, 0);

long long sum(int N, int numThrees){
	if(numThrees == 1){
		return N;
	}
	if(memo[N][numThrees] != -1){
		return memo[N][numThrees];
	}
	long long retVal = fact[N+numThrees]*invFact[numThrees]%MOD*invFact[N-1]%MOD;
	// double temp = 1;
	// for(int i = 1; i <= numThrees; i++){
	// 	temp /= i;
	// 	temp *= i + N - 1;
	// 	temp = (int) temp % MOD;
	// }
	// long long retVal = 1;
	// for(int i = 1; i <= N-3; i++){
	// 	retVal += sum(i, numThrees - 1);
	// 	retVal %= MOD;
	// }
	cout << N << " " << numThrees << " " << retVal << endl;
	memo[N][numThrees] = retVal;
	return retVal;
}

long long calcInvFact(long long x, int power){
	if(power == 0){
		return 1;
	} else if(power == 1){
		return x;
	} else {
		int newPow = power / 2;
		long long val = calcInvFact(x, newPow);
		if(power % 2 == 0){
			return (val*val)%MOD;
		} else {
			return (((val*val)%MOD)*x)%MOD;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	for(int i = 0; i < 10000; i++){
		vector<long long> empty (3334, -1);
		memo.push_back(empty);
	}
	fact[0] = 1;
	invFact[0] = 1;
	for(int i = 1; i < 15000; i++){
		fact[i] = fact[i-1]*i % MOD;
		invFact[i] = calcInvFact(fact[i], MOD - 2);
		if(i < 20) cout << fact[i] << " " << invFact[i] << endl;
	}
	int T; cin >> T;
	while(T--){
		int N; cin >> N;
		int third = N/3;
		int tot = 0;
		for(int i = 1; i <= third; i++){
			tot += sum(N-2 - 3*(i - 1), i);
			tot %= MOD;
		}
		tot *= 2;
		tot--;
		tot %= MOD;
		int power = 1;
		for(int i = 0; i < third; i++){
			power *= 2;
			power %= MOD;
		}
		tot += power;
		tot %= MOD;
		cout << tot << endl;
	}

	return 0;
}