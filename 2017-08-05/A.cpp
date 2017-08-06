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
	
	int A, B, C; cin >> A >> B >> C;

	if(A == B && A == C) {
		cout << "*" << endl;
	} else if (A == B) {
		cout << "C" << endl;
	} else if (A == C) { 
		cout << "B" << endl;
	} else {
		cout << "A" << endl;
	}

	return 0;
}