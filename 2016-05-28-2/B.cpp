#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	long long N, b; cin >> N >> b;
	if(pow(2, b+1) > N){
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}
	
	return 0;
}