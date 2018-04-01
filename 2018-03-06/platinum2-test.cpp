#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cout << "1500 1500 50000" << endl;
	bool outA = false, outB = false;
	for(int i = 0; i < 1500; i++) {
		for(int j = 0; j < 1500; j++) {
			int i = rand();
			if(i % 2) {
				if(!outA) {
					int j = rand();
					if(j % 10 == 0) {
						outA = true;
						cout << 'A';
					}
				} else if (!outB) {
					int j = rand();
					if(j % 10 == 0) {
						outB = true;
						cout << 'B';
					}
				} else cout << '.';
			} else {
				cout << '#';
			}
		}
		cout << endl;
	}
	for(int i = 0; i < 50000; i++) {
		cout << rand() % 1500 + 1 << " " << rand() % 1500 + 1 << endl;
	}

	return 0;
}