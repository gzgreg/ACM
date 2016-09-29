#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int H, B;
vector<int> h, b;

vector<int> numPacksH (120000, 600);
vector<int> numPacksB (120000, 600);
int minPossible = 1e9;

void dp(set<int> unusedH, int numB, bool isB, vector<int> vec) {
	if((isB && numPacksB[numB] < B - unusedH.size())
		|| (!isB && numPacksH[numB] < H - unusedH.size())) {
		return;
	}
	if(isB) {
		numPacksB[numB] = B - unusedH.size();
	} else {
		numPacksH[numB] = H - unusedH.size();
	}
	for(int i : unusedH) {
		set<int> newH = set<int>(unusedH);
		newH.erase(i);
		int newNum = numB + vec[i];
		dp(newH, newNum, isB, vec);
	}
}

int main(){
	ios::sync_with_stdio(0);

	cin >> H;
	set<int> unusedH, unusedB;
	for(int i = 0; i < H; i++) {
		int curr; cin >> curr; h.push_back(curr);
		unusedH.insert(i);
	}
	cin >> B;
	for(int i = 0; i < B; i++) {
		int curr; cin >> curr; b.push_back(curr);
		unusedB.insert(i);
	}

	dp(unusedH, 0, false, h);
	for(int i = 0; i < 50; i++) {
		cout << numPacksH[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < 50; i++) {
		cout << numPacksB[i] << " ";
	}
	cout << endl;
	dp(unusedB, 0, true, b);
	for(int i = 0; i < 50; i++) {
		cout << numPacksH[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < 50; i++) {
		cout << numPacksB[i] << " ";
	}
	cout << endl;
	int minPacks = 500;
	for(int i = 1; i < numPacksH.size(); i++) {
		if(numPacksH[i] < 500 && numPacksB[i] < 500) {
			cout << numPacksH[i] << " " << numPacksB[i] << " " << i << endl;
			minPacks = min(minPacks, numPacksH[i] + numPacksB[i]);
		}
	}
	if(minPacks < 300) {
		cout << minPacks << endl;
		return 0;
	}
	cout << "impossible" << endl;

	return 0;
}