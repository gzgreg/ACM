#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'
#define MOD 1000000000

vector<ll> matExp(vector<ll> mat, long long exp) {
	vector<ll> out = {1, 0, 0, 1};
	vector<ll> prev = mat;
	while(exp > 0) {
		if(exp % 2 == 1) {
			//out = out * mat
			vector<ll> tmp (4, 0);
			tmp[0] = (out[0] * mat[0] + out[1] * mat[2]) % MOD;
			tmp[1] = (out[0] * mat[1] + out[1] * mat[3]) % MOD;
			tmp[2] = (out[2] * mat[0] + out[3] * mat[2]) % MOD;
			tmp[3] = (out[2] * mat[1] + out[3] * mat[3]) % MOD;
			out = tmp;
		}
		exp = exp / 2;
		vector<ll> tmp (4, 0);
		tmp[0] = (mat[0] * mat[0] + mat[1] * mat[2]) % MOD;
		tmp[1] = (mat[0] * mat[1] + mat[1] * mat[3]) % MOD;
		tmp[2] = (mat[2] * mat[0] + mat[3] * mat[2]) % MOD;
		tmp[3] = (mat[2] * mat[1] + mat[3] * mat[3]) % MOD;
		mat = tmp;
	}
	return out;
}

int main(){
	ios::sync_with_stdio(0);
	
	int P; cin >> P;

	while(P--) {
		long long K, Y; cin >> K >> Y;

		vector<ll> ans = matExp({1, 1, 1, 0}, Y);

		cout << K << " " << ans[2] << endl;
	}

	return 0;
}