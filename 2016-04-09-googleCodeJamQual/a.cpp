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
	for(int j = 1; j <= T; j++){
		int N; cin >> N;
		if(N == 0){
			cout << "Case #" << j << ": " << "INSOMNIA" << endl;
			continue;
		}
		int currNum = N;
		int seen = 0;
		while(seen != 1023){
			int tempNum = currNum;
			for(int i = 0; i < log10(currNum+1); i++){
				int currDig = tempNum % 10;
				//cout << currDig << " ";
				seen = seen | (1 << currDig);
				tempNum = tempNum / 10;
			}
			//cout << seen << endl;
			currNum += N;
		}

		cout << "Case #" << j << ": " << currNum - N << endl;
	}
	
	return 0;
}