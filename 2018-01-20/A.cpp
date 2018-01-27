#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000003

long long mod_pow(long long base, long long  exp) {
	long long val = 1;
	base = base % MOD;
	
	while(exp > 0) {
		if(exp % 2 == 1) {
			val *= base;
			val %= MOD;
		}
		exp = exp / 2;
		base *= base;
		base %= MOD;
	}
	return val;
}

int parent[1001];

int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }
void merge(int x, int y) { parent[find(x)] = find(y); }

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, F; cin >> n >> F;
	for(int i = 0; i < n; i++) {
		parent[i] = i;
	}
	vector<bitset<1000>> sets;
	for(int i = 0; i < F; i++) {
		int sz; cin >> sz;
		bitset<1000> curSet;
		for(int j = 0; j < sz; j++) {
			int cur; cin >> cur; curSet[cur-1] = true;
		}
		if(curSet[0]) {
			curSet.flip();
		}
		sets.push_back(curSet);
	}

	F++;
	sets.push_back(bitset<1000>(0));

	vector<bitset<1000>> revSets(n);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < F; j++) {
			revSets[i][j] = sets[j][i];
		}
	}

	bitset<1000> allOnes, allZeros(0);
	for(int i = 0; i < F; i++) {
		allOnes[i] = 1;
	}
	int power = n;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if((revSets[i] ^ revSets[j]) == allZeros) {
				merge(i, j);
			}
		}
	}

	set<int> numCats;
	for(int i = 0; i < n; i++) {
		numCats.insert(parent[i]);
	}

	cout << mod_pow(2, numCats.size()) << endl;

	return 0;
}