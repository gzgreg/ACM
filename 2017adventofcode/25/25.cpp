#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

unordered_map<int, bool> tape;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int state = 0;
	int pos = 0;

	for(int it = 0; it < 12794428; it++) {
		switch(state) {
			case 0:
				if(tape[pos] == 0) {
					tape[pos] = 1;
					pos++;
					state = 1;
				} else {
					tape[pos] = 0;
					pos--;
					state = 5;
				}
				break;
			case 1:
				if(tape[pos] == 0) {
					tape[pos] = 0;
					pos++;
					state = 2;
				} else {
					tape[pos] = 0;
					pos++;
					state = 3;
				}
				break;
			case 2:
				if(tape[pos] == 0) {
					tape[pos] = 1;
					pos--;
					state = 3;
				} else {
					tape[pos] = 1;
					pos++;
					state = 4;
				}
				break;
			case 3:
				if(tape[pos] == 0) {
					tape[pos] = 0;
					pos--;
					state = 4;
				} else {
					tape[pos] = 0;
					pos--;
					state = 3;
				}
				break;
			case 4:
				if(tape[pos] == 0) {
					tape[pos] = 0;
					pos++;
					state = 0;
				} else {
					tape[pos] = 1;
					pos++;
					state = 2;
				}
				break;
			case 5:
				if(tape[pos] == 0) {
					tape[pos] = 1;
					pos--;
					state = 0;
				} else {
					tape[pos] = 1;
					pos++;
					state = 0;
				}
				break;
		}
	}
	
	int ans = 0;
	for(auto cur : tape) {
		ans += cur.second;
	}
	cout << ans << endl;

	return 0;
}