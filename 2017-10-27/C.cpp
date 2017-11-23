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

	int n; cin >> n;

	vector<pair<string, int>> commands;

	for(int i = 0; i < n; i++) {
		string s; int xi; cin >> s >> xi;
		commands.push_back({s, xi});
	}

	vector<bitset<10>> actionPerBit(2);

	actionPerBit[1] = bitset<10>(1023);

	for(int i = 0; i < n; i++) {
		string op = commands[i].first;
		int num = commands[i].second;
		if(op == "|") {
			actionPerBit[0] |= num;
			actionPerBit[1] |= num;
		} else if (op == "&") {
			actionPerBit[0] &= num;
			actionPerBit[1] &= num;
		} else {
			actionPerBit[0] ^= num;
			actionPerBit[1] ^= num;
		}
	}

	bitset<10> xorNum(0), andNum(1023), orNum(0);

	for(int i = 0; i < 10; i++) {
		if(actionPerBit[0][i]) {
			if(actionPerBit[1][i]) {
				orNum[i] = true;
			} else {
				xorNum[i] = true;
			}
		} else {
			if(!actionPerBit[1][i]) {
				andNum[i] = false;
			}
		}
	}

	cout << 3 << endl;
	cout << "| " << orNum.to_ulong() << endl;
	cout << "& " << andNum.to_ulong() << endl;
	cout << "^ " << xorNum.to_ulong() << endl; 
	
	return 0;
}