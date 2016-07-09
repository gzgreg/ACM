#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	
	int N, B, T;
	while(cin >> N){
		cin >> B >> T;
		int Btot = 0, Ttot = 0;
		int Bcurr = 0, Tcurr = 0;
		while(N > 0){
			if(Bcurr == 0 && Tcurr == 0){
				int Bget = min(B, N);
				Bcurr += Bget;
				N -= Bget;
				int Tget = min(T, N);
				Tcurr += Tget;
				N -= Tget;
				
			} else if(Bcurr == 0){
				Bcurr += min(B, N);
				N -= Bcurr;
				Tcurr--;
				Ttot++;
			} else if(Tcurr == 0){
				Tcurr += min(T, N);
				N -= Tcurr;
				Bcurr--;
				Btot++;
			} else {
				int eaten = min(Bcurr, Tcurr);
				Bcurr -= eaten;
				Tcurr -= eaten;
				Btot += eaten;
				Ttot += eaten;
			}
		}
		cout << Bcurr+Btot << " " << Tcurr+Ttot << endl;
	}

	return 0;
}