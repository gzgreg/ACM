#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<bool> primes (5e6+1, true);
vector<ll> primeList;

void calcPrimes() {
	for(int i = 2; i < 3000; i++) {
		if(primes[i]) {
			primeList.push_back(i);
			int curr = 2*i;
			while(curr <= 5000000) {
				primes[curr] = false;
				curr += i;
			}
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

	int N; cin >> N;
	calcPrimes();
	vector<vector<int>> result(N+1, vector<int>((N+1) / 2));
	for(int id = 0; id <= N; id++) {
		vector<int> data(id);
		std::iota(data.begin(), data.end(), 0);
		map<int, int> teeth;
		do {
			int cnt = 0;
			for(int i = 1; i < id-1; i++) {
				if(data[i] > data[i-1]
					&& data[i] > data[i+1]) {
					cnt++;
				}
			}
			teeth[cnt]++;
		} while(next_permutation(data.begin(), data.end()));
		for(auto cur : teeth) {
			result[id][cur.first] = cur.second;
		}
	}
	for(int i = 1; i < result.size(); i++) {
		for (int j = 1; j < result[0].size(); j++) {
			cout << setw(10) << result[i][j] / result[i-1][0] << " ";
		}
		cout << endl;
	}
	return 0;
}