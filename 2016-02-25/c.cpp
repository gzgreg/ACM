#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int n, m; cin >> n >> m;

	int nMult = 0, mMult = 0;

	while(n > 0 || m > 0){
		if(n > 0){
			if((nMult + 1)*2 == mMult * 3){
				if(n > m * 2 && n >= 2){
					nMult+=2;
					n-=2;
					m++;
				} else {		
					nMult += 2;
					n--;
				}
			} else {
				nMult++;
				n--;
			}
		}
		if(m > 0){
			mMult++;
			m--;
		}
	}

	cout << max(nMult*2, mMult*3) << endl;

	return 0;
}