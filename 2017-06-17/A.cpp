#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int h, m; char c; cin >> h >> c >> m;

	for(int i = 0; i < 1440; i++) {
		int currH, currM;
		currM = (m + i) % 60;
		currH = (h + (m + i) / 60) % 24;
		if(currH % 10 == currM / 10
			&& currM % 10 == currH / 10) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}