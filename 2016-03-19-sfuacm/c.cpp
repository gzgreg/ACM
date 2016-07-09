#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int R, P;
	while(cin >> R >> P){
		if(R > P){
			cout << "Interpersonal" << endl;
		} else if(R == P){
			cout << "Either" << endl;
		} else {
			cout << "Technical" << endl;
		}
	}
	
	return 0;
}