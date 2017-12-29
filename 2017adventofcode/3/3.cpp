#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	int n; cin >> n;
	complex<int> curLoc = {0, 0};

	int numSteps = 1;
	int sz = 1;
	int left = 1;
	int curStep = 0;
	complex<int> curDir = {0, 1};

	map<int, map<int, int>> vals;
	vals[0][0] = 1;
	while(vals[curLoc.real()][curLoc.imag()] <= n) {
		numSteps++;
		curStep++;
		curLoc += curDir;
		if(curStep == sz) {
			if(left == 1) {
				left--;
				curDir *= complex<int>(0, 1);
			} else {
				left = 1;
				curDir *= complex<int>(0, 1);
				sz++;
			}
			curStep = 0;
		}
		vals[curLoc.real()][curLoc.imag()] += vals[curLoc.real()+1][curLoc.imag()];
		vals[curLoc.real()][curLoc.imag()] += vals[curLoc.real()-1][curLoc.imag()];
		vals[curLoc.real()][curLoc.imag()] += vals[curLoc.real()][curLoc.imag()+1];
		vals[curLoc.real()][curLoc.imag()] += vals[curLoc.real()][curLoc.imag()-1];
		vals[curLoc.real()][curLoc.imag()] += vals[curLoc.real()+1][curLoc.imag()+1];
		vals[curLoc.real()][curLoc.imag()] += vals[curLoc.real()-1][curLoc.imag()-1];
		vals[curLoc.real()][curLoc.imag()] += vals[curLoc.real()-1][curLoc.imag()+1];
		vals[curLoc.real()][curLoc.imag()] += vals[curLoc.real()+1][curLoc.imag()-1];
	}
	cout << numSteps << endl;
	cout << vals[curLoc.real()][curLoc.imag()] << endl;
	
	return 0;
}