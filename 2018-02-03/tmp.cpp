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
	cout << 5000000 << endl;
	for(int i = 0; i < 5000000; i++) {
		cout << (i == 0 ? 0 : rand() % i)  << " ";
	}
	cout << endl;
	
	return 0;
}