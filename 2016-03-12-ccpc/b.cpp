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
	for(int i = 0; i < T; i++){
		char a, b; cin >> a >> b;
		if(a == 'N'){
			if(b == 'S'){
				cout << "U-turn" << endl;
			} else if(b == 'E'){
				cout << "right" << endl;
			} else if(b == 'W'){
				cout << "left" << endl;
			}
		}
		if(a == 'S'){
			if(b == 'N'){
				cout << "U-turn" << endl;
			} else if(b == 'E'){
				cout << "left" << endl;
			} else if(b == 'W'){
				cout << "right" << endl;
			}
		}
		if(a == 'E'){
			if(b == 'W'){
				cout << "U-turn" << endl;
			} else if(b == 'N'){
				cout << "left" << endl;
			} else if(b == 'S'){
				cout << "right" << endl;
			}
		}
		if(a == 'W'){
			if(b == 'E'){
				cout << "U-turn" << endl;
			} else if(b == 'S'){
				cout << "left" << endl;
			} else if(b == 'N'){
				cout << "right" << endl;
			}
		}
	}
	
	return 0;
}