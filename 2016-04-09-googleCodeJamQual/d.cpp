#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;

	for(int i = 1; i <= T; i++){
		int K, C, S; cin >> K >> C >> S;

		long long output = pow(K, C-1);
		cout << "Case #" << i << ": "; 
		for(int j = 0; j < K; j++){
			cout << output*j + 1 << " ";
		}

		cout << endl;		
	}
	
	return 0;
}