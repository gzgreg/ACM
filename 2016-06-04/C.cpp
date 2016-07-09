#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	multiset<int> l;

	int n; cin >> n;

	for(int i = 0; i < n; i++){
		int curr; cin >> curr; l.insert(curr);
	}

	if(n == 2) {
		cout << "YES" << endl;
		cout << *(l.begin()) + *(++l.begin()) - 1 << endl;
		return 0;
	}

	int lg = *(--l.end());
	int sm1 = *(l.begin());
	int sm2 = *(++l.begin());
	if(lg - sm1 + 1 > sm1 + sm2 - 1){
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		cout << sm1 + sm2 - 1 << endl;
	}
	
	return 0;
}