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

	string s1, s2; cin >> s1 >> s2;
	if(s1.size() >= s2.size()) {
		cout << "go" << endl;
	} else {
		cout << "no" << endl;
	}
	
	return 0;
}