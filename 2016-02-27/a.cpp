#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int C; cin >> C;

	for(int x = 0; x < C; x++){
		string s; cin >> s;
		long long N, T, L; cin >> N >> T >> L;
		long long opsPerCase = floor(L*100000000/T);
		long long val;
		bool ans = true;
		if(s.find("2^N") != string::npos){
			val = 1;
			while(N--){
				val *= 2;
				if(val > opsPerCase){
					ans = false;
					break;
				}
			}
		} else if(s.find("N!") != string::npos){
			val = 1;
			for(int i = 2; i <= N; i++){
				val *= i;
				if(val > opsPerCase){
					ans = false;
					break;
				}
			}
		} else if(s.find("N^3") != string::npos){
			val = N*N*N;
			if(val > opsPerCase){
				ans = false;
			}
		} else if(s.find("N^2") != string::npos){
			val = N*N;
			if(val > opsPerCase){
				ans = false;
			}
		} else {
			val = N;
			if(val > opsPerCase){
				ans = false;
			}
		}
		if(ans){
			cout << "May Pass." << endl;
		} else {
			cout << "TLE!" << endl;
		}
	}

	return 0;
}