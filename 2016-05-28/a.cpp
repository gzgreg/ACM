#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	long long a, b, c;
	cin >> a >> b >> c;
	if((a > b && c > 0) || (c < 0 && a < b) || (c == 0 && a != b)){
		cout << "NO" << endl;
	} else {
		if(c == 0){
			cout << "YES" << endl;
			return 0;
		}
		if((b-a) % c == 0){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}