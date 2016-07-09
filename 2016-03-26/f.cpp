#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	freopen("positive.in", "r", stdin);
	freopen("positive.out", "w", stdout);

	int n; cin >> n;

	int cumsum = 0;

	for(int i = 0; i < n; i++){
		int curr; cin >> curr;
		cumsum += curr;
	}

	cout << max(cumsum, 0) << endl;

	return 0;
}