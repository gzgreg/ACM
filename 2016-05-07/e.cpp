#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'
#define MOD 5318008

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;

	while(T--){
		int N; cin >> N;
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

		int diffx = abs(x1 - x2);
		int diffy = abs(y1 - y2);

		int nondiag = abs(diffx - diffy); //number of nondiagonal moves
		int diag = max(diffx, diffy) - nondiag;

		//need (nondiag + diag)! / diag! / nondiag!
		long long ans = 1;
		for(int i = max(nondiag, diag) + 1; i <= nondiag + diag; i++){
			ans *= i;
			ans /= i - max(nondiag, diag);
			ans %= MOD;
		}
		cout << ans << endl;
	}
	
	return 0;
}