#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int size = 35651584;
	string state = "11011110011011101";

	while(state.size() < size) {
		string back = state;
		reverse(back.begin(), back.end());
		for(int i = 0; i < back.size(); i++) {
			if(back[i] == '0' ) {
				back[i] = '1';
			} else {
				back[i] = '0';
			}
		}
		state = state + "0" + back;
	}

	state = state.substr(0, size);

	while(state.size() % 2 == 0) {
		string checkSum = "";
		for(int i = 0; i < state.size() / 2; i++) {
			if(state[2*i] == state[2*i + 1]) {
				checkSum.append("1");
			} else {
				checkSum.append("0");
			}
		}
		state = checkSum;
	}
	cout << state << endl;
	
	return 0;
}