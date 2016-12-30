#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	int N = 3001330;
	int prevAns = 2;

	for(int i = 4; i <= N; i++) {
		prevAns = 1 + prevAns;
		prevAns %= (i - 1);
		if(prevAns >= i / 2) prevAns++;
	}
	cout << prevAns << endl;

	return 0;
}