#include <bits/stdtr1c++.h>

using namespace std;

int main(){
	int W, S; cin >> W >> S;
	int X, Y; cin >> X >> Y;
	int pieces[W][X];
	int steps[X]; memset(steps, 0, sizeof steps);
	for(int i = 0; i < W; i++){
		for(int j = 0; j < X; j++){
			cin >> pieces[i][j];
		}
	}

	for(int i = 0; i < S; i++){
		for(int j = 0; j < X; j++){
			int si; cin >> si;
			if(si > steps[j]) steps[j] = si;
		}
	}

	for(int i = 0; i < W; i++){
		for(int j = 0; j < X; j++){
			int newHeight = Y - steps[j];
			if(newHeight > pieces[i][j]){
				cout << pieces[i][j];
			} else {
				cout << newHeight;
			}
			cout << " ";
		}
		cout << "\n";
	}
	return 0;
}