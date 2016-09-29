#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'
#define PI 3.141592653
vector<string> fact = {"1", "1", "2", "6", "24", "120", "720", "5040", "40320", "362880"};
int main(){
	ios::sync_with_stdio(0);

	string s; cin >> s;

	if(s == "0" || s == "1") {
		cout << 1 << endl;
		return 0;
	}

	for(int i = 220000; i >= 2; i--) {
		if((int) (log10(2*PI*i) / 2 + i * (log10(i) - log10(2.718281828459)) / log10(10) + 1) <= s.size()) {
			if(i < 10) {
				if(fact[i] == s) {
					cout << i << endl;
					return 0;
				}
			} else {
				cout << i << endl;
				return 0;
			}
		}
	}
	
	return 0;
}