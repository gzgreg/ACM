#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > u;
vector<vector<long> > memo;
vector<vector<long> > cumsum;

long calc(int f, int l){
	int plus = f == 0 ? 0 : l == 0 ? 0 : cumsum[f-1][f-1];
	int minus1 = f == 0 ? 0 : cumsum[f-1][l-1];
	int minus2 = f == 0 ? 0 : cumsum[l-1][f-1];

	return (cumsum[l-1][l-1] - minus1 - minus2 + plus) / 2;
}

void recurse(int k, int l, int r, int bl, int br){
	if(l > r) return;
	long m = 1E9;
	int icurr = 1;
	for(int i = bl; i <= min(br, (l+r) / 2); i++){
		long curr = memo[i][k-1] + calc(i, (l+r) / 2);
		if(curr < m){
			icurr = i;
			m = curr;
		}
	}
	memo[(l + r) / 2][k] = m;

	recurse(k, l, (l+r)/2 - 1, bl, icurr);
	recurse(k, (l+r) / 2 + 1, r, icurr, br);
}

int main(){
	int n, k; cin >> n >> k;
	getchar();
	for(int i = 0; i < n; i++){
		vector<int> empty;
		u.push_back(empty);
		for(int j = 0; j < n; j++){
			u[i].push_back(getchar() - '0');
			getchar();
		}
	}

	for(int i = 0; i <= n; i++){
		vector<long> kf (k+1, -1);
		vector<long> nf (n+1, -1);
		memo.push_back(kf);
		cumsum.push_back(nf);
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int plus = i == 0 ? 0 : j == 0 ? 0 : cumsum[i-1][j-1];
			int minus1 = i == 0 ? 0 : cumsum[i-1][j];
			int minus2 = j == 0 ? 0 : cumsum[i][j-1];

			cumsum[i][j] = u[i][j] + minus1 + minus2 - plus;
		}
	}

	for(int i = 1; i <= k; i++){
		if(i == 1){
			for(int j = 1; j <= n; j++){
				memo[j][i] = calc(0, j);
			}
		} else {
			recurse(i, 1, n, 1, n);
		}
	}

	cout << memo[n][k] << endl;

	return 0;
}