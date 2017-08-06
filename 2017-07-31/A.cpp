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
	
	int s, v1, v2, t1, t2; cin >> s >> v1 >> v2 >> t1 >> t2;

	int tot1 = 2*t1 + v1*s;
	int tot2 = 2*t2 + v2*s;
	if(tot1 > tot2) {
		cout << "Second" << endl;
	} else if (tot1 == tot2) {
		cout << "Friendship" << endl;
	} else {
		cout << "First" << endl;
	}

	return 0;
}