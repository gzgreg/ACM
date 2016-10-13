#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int M;

vector<vector<int>> matrixMultiply(vector<vector<int>> mat1, vector<vector<int>> mat2) {
	vector<vector<int>> newMat(mat1.size(), vector<int> (mat2[0].size(), 0));
	for(int i = 0; i < mat1.size(); i++) {
		for(int j = 0; j < mat2[0].size(); j++) {
			for(int k = 0; k < mat1[0].size(); k++) {
				newMat[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	return newMat;
}

vector<vector<int>> modMatrix(vector<vector<int>> mat) {
	for(int i = 0; i < mat.size(); i++) {
		for(int j = 0; j < mat[i].size(); j++){
			mat[i][j] %= M;
		}
	}
	return mat;
}

vector<vector<int>> mod_Matrixpow(vector<vector<int>> base, int exp) {
	vector<vector<int>> val (base.size(), vector<int>(base.size(), 0));
	for(int i = 0; i < base.size(); i++) {
		val[i][i] = 1;
	}
	
	while(exp > 0) {
		if(exp % 2 == 1) {
			val = matrixMultiply(val, base);
			val = modMatrix(val);
		}
		exp = exp / 2;
		base = matrixMultiply(base, base);
		base = modMatrix(base);
	}
	return val;
}

int main(){
	ios::sync_with_stdio(0);

	int N, A, B, C, T; cin >> N >> M >> A >> B >> C >> T;

	while(N || M || A || B || C || T) {
		vector<vector<int>> initial (N, vector<int> (1, 0));
		vector<vector<int>> matrix (N, vector<int>(N, 0));

		for(int i = 0; i < N; i++) {
			cin >> initial[i][0];

			if(i > 0) {
				matrix[i][i-1] = A;
			}
			matrix[i][i] = B;
			if(i < N-1) {
				matrix[i][i+1] = C;
			}
		}

		matrix = mod_Matrixpow(matrix, T);

		vector<vector<int>> ans = matrixMultiply(matrix, initial);
		ans = modMatrix(ans);
		for(int i = 0; i < N; i++) {
			cout << ans[i][0] << " ";
		}
		cout << endl;

		cin >> N >> M >> A >> B >> C >> T;
	}
	
	return 0;
}