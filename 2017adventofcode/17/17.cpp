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

	vector<int> ans;
	ans.push_back(0);
	int curPos = 0;
	int zeroPos = 0;
	int afterZero;
	for(int i = 1; i <= 50000000; i++) {
		curPos += 371;
		curPos %= i;
		//cout << curPos << " ";
		if(curPos < zeroPos) {
			zeroPos++;
		} else if(curPos == zeroPos) {
			afterZero = i;
			cout << i << endl;
		}
		curPos++;
	}
	cout << zeroPos << " " << afterZero << endl;
	
	return 0;
}