#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<bool> primes (1e6 + 1, true);
vector<ll> primeList;

void calcPrimes() {
	for(int i = 2; i <= 1000; i++) {
		if(primes[i]) {
			primeList.push_back(i);
			int curr = i*i;
			while(curr <= 1000000) {
				primes[curr] = false;
				curr += i;
			}
		}
	}
	for(int i = 1001; i <= 1e6; i++) {
		if(primes[i]) {
			primeList.push_back(i);
		}
	}
}

ll prime(ll val) {
	if(primes[val]) return val;
	for(int i : primeList) {
		if(val % i == 0) {
			return i;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n, x, y; cin >> n >> x >> y;
	calcPrimes();
	vector<ll> vals (2e6+1), tot(2e6+1);
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur;
		vals[cur] += cur;
		tot[cur]++;
	}

	vector<ll> cumVals = {0}, cumTot = {0};
	for(int i = 1; i < 2e6+1; i++) {
		cumVals.push_back(cumVals[i-1] + vals[i]);
		cumTot.push_back(cumTot[i-1] + tot[i]);
	}

	ll bestAns = x*vals.size();
	for(int i = 0; i < primeList.size(); i++) {
		ll curAns = 0;
		ll curP = primeList[i];
		for(int j = curP; j <= 1e6 + curP; j += curP) {
			ll thresh = max(j - curP, j - x/y-1);
			curAns += y*(j*(cumTot[j]-cumTot[thresh]) 
					- (cumVals[j] - cumVals[thresh]));
			curAns += x*(cumTot[thresh] - cumTot[j - curP]);
		}
		if(curAns < bestAns) {
			bestAns = curAns;
		}
	}
	cout << bestAns << endl;
	return 0;
}