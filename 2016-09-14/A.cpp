#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int P; cin >> P;
	while(P--) {
		long long K; cin >> K;
		long long N; cin >> N;

		cout << K << " ";
		cout << N*(N+1) / 2 << " ";
		cout << N*N << " ";
		cout << N*(N+1) << endl;
	}
	
	return 0;
}