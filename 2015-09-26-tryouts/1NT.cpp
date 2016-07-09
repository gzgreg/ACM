using namespace std;

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>

int main(){
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		string s;
		int suits[4] = {0};
		int HCP = 0;
		for(int j = 0; j < 13; j++){
			cin >> s;
			char val = s.at(0);
			char suit = s.at(1);
			if(val == 'A'){
				HCP += 4;
			} else if(val == 'K'){
				HCP += 3;
			} else if(val == 'Q'){
				HCP += 2;
			} else if(val == 'J'){
				HCP += 1;
			}

			if(suit == 'C'){
				suits[0]++;
			} else if(suit == 'D'){
				suits[1]++;
			} else if(suit == 'H'){
				suits[2]++;
			} else if(suit == 'S'){
				suits[3]++;
			}
		}
		if(HCP >= 15 && HCP <= 17){
			sort(suits, suits+4);
			if((suits[0] == 2 && suits[1] == 3 && suits[2] == 3 && suits[3] == 5) ||
				(suits[0] == 2 && suits[1] == 3 && suits[2] == 4 && suits[3] == 4) ||
				(suits[0] == 3 && suits[1] == 3 && suits[2] == 3 && suits[3] == 4)){
				cout << "1NT" << endl;
			} else {
				cout << "Pass" << endl;
			}
		} else {
			cout << "Pass" << endl;
		}
	}
	return 0;
}