#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;

	while(T--){
		int R, B; cin >> R >> B;

		if(R < B / sqrt(2)){
			cout << fixed << setprecision(3) << (double) 2*R*R << endl;
			continue;
		}

		double W;
		W = sqrt(R*R - ((double)B / 2)*((double)B / 2))*2;
		cout << fixed << setprecision(3) << W*B << endl;
	}

	return 0;
}