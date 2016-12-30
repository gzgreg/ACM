#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	vector<vector<char>> keypad = {{'0', '0', '1', '0', '0'},
								   {'0', '2', '3', '4', '0'}, 
								   {'5', '6', '7', '8', '9'}, 
								   {'0', 'A', 'B', 'C', '0'},
								   {'0', '0', 'D', '0', '0'}
								};
	int x = 0, y = 2;
	int lastX = x, lastY = y;
	string s;
	while(cin >> s) {
		for(char i : s) {
			switch(i) {
				case 'U':
					x--;
					break;
				case 'L':
					y--;
					break;
				case 'R':
					y++;
					break;
				case 'D':
					x++;
					break;
			}
			if( x >= 5 || x < 0 || y >= 5 || y < 0 || keypad[x][y] == '0') {
				x = lastX;
				y = lastY;
			}
			lastX = x;
			lastY = y;
		}

		cout << keypad[x][y] << endl;
	}
	
	return 0;
}