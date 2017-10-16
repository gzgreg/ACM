#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'
int H;

vector<int> triangle (1, 0);

vector<vector<double>> assign(vector<vector<double>> mat, int idx, 
	double p0, double p1, double p2, double p3, double p4) {
	vector<double> row (H * 2, 0);
	row[H + idx] = p4;
	int idRow = sqrt((idx + 1) * 2);
	if(triangle[idRow] < (idx + 1)) idRow++;
	if(abs(p0) > 1e-5) {
		row[idx - idRow] = p0;
	}
	if(abs(p1) > 1e-5) {
		row[idx - idRow + 1] = p1;
	}
	if(abs(p2) > 1e-5) {
		row[idx + idRow] = p2;
	}
	if(abs(p3) > 1e-5) {
		row[idx + idRow+ 1] = p3;
	}

	mat.push_back(row);
	return mat;
}

vector<vector<double>> square(vector<vector<double>> mat) {
	vector<vector<double>> newMat(mat.size(), vector<double> (mat.size(), 0));
	for(int i = 0; i < mat.size(); i++) {
		for(int j = 0; j < mat.size(); j++) {
			double total = 0;
			for(int k = 0; k < mat.size(); k++) {
				newMat[i][j] += mat[i][k] * mat[k][j];
			}
		}
	}
	return newMat;
}

int main(){
	ios::sync_with_stdio(0);

	int N; cin >> N;

	for(int i = 1; i <= 528; i++) {
		triangle.push_back(i*(i+1) / 2);
	}

	vector<int> nums(N*(N+1) / 2, 0);
	H = N*(N+1) / 2;
	for(int i = 0; i < nums.size(); i++) {
		cin >> nums[i];
	}

	vector<vector<double>> matrix;
	for(int i = 0; i < H; i++) {
		double p0, p1, p2, p3, p4; cin >> p0 >> p1 >> p2 >> p3 >> p4;
		matrix = assign(matrix, i, p0, p1, p2, p3, p4);
	}
	for(int i = 0; i < H; i++) {
		matrix.push_back(vector<double> (H * 2, 0));
		matrix[H+i][H+i] = 1;
	}
	for(int i = 0; i < 7; i++) {
		matrix = square(matrix);
	}
	double expected = 0;
	for(int i = 0; i < H; i++) {
		expected += matrix[0][H + i] * nums[i];
	}

	cout << fixed << setprecision(10) << expected;

	return 0;
}