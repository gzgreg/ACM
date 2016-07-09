#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int B, T;
double f;
vector<double> p;
vector<int> s;
vector<vector<vector<double>>> memo;
vector<int> fails;

double dp(int Tleft, bitset<10> fixed, int totalF){
	if(Tleft == 0){
		return 0;
	} else if(memo[totalF][Tleft][fixed.to_ulong()] >= 0){
		return memo[totalF][Tleft][fixed.to_ulong()];
	} else {
		int idx = 11;
		double expVal = 0;
		for(int i = 0; i < B; i++){
			if(!fixed[i] && s[i]*p[i] > expVal){
				idx = i;
				expVal = s[i]*p[i];
			}
		}
		if(idx == 11) return 0;
		bitset<10> ifFixed = fixed; ifFixed[idx] = true;
		double saveP = p[idx];
		p[idx] = p[idx] * f;
		fails[idx]++;
		double ans = (1-saveP)*dp(Tleft-1, fixed, totalF + 1);
		p[idx] = saveP; fails[idx]--;
		ans += p[idx]*(s[idx] + dp(Tleft - 1, ifFixed, totalF - fails[idx]));
		memo[totalF][Tleft][fixed.to_ulong()] = ans;
		return ans;
	}
}

int main(){
	ios::sync_with_stdio(0);

	cin >> B >> T >> f;
	for(int i = 0; i < B; i++){
		double pcurr; int scurr; cin >> pcurr >> scurr;
		p.push_back(pcurr);
		s.push_back(scurr);
	}
	fails = vector<int>(B, 0);

	memo = vector<vector<vector<double>>> (T+1, vector<vector<double>>(T+1, vector<double>(1025, -2)));

	cout << fixed << setprecision(10) << dp(T, bitset<10>(0), 0) << endl;
	
	return 0;
}