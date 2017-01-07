#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int n, k; cin >> n >> k;

	int t = 240 - k;

	int total = -1, i = 1;

	while(t >= 0) {
		t -= 5*i;
		i++;
		total++;
	}

	if(t == 0) t++;

	cout << min(total, n) << endl;
	
	return 0;
}