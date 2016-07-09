#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

using namespace std;

int main(){
	int logo[6];
	for(int i = 0; i < 6; i++){
		cin >> logo[i];
	}
	double sideT = sqrt(logo[0] * logo[1] + logo[2]*logo[3] + logo[4]*logo[5]);
	if(abs(sideT - round(sideT)) > 1e-13){
		cout << -1;
		return 0;
	}
	int side = round(sideT);

	if((logo[0] == side || logo[1] == side) && (logo[2] == side || logo[3] == side) && (logo[4] == side || logo[5] == side)){
		cout << side << endl;
		int currSide = logo[0] == side ? logo[1] : logo[0];
		for(int i = 0; i < currSide; i++){
			for(int j = 0; j < side; j++){
				cout << "A";
			}
			cout << endl;
		}
		currSide = logo[2] == side ? logo[3] : logo[2];
		for(int i = 0; i < currSide; i++){
			for(int j = 0; j < side; j++){
				cout << "B";
			}
			cout << endl;
		}
		currSide = logo[4] == side ? logo[5] : logo[4];
		for(int i = 0; i < currSide; i++){
			for(int j = 0; j < side; j++){
				cout << "C";
			}
			cout << endl;
		}
	} else {
		int *ptr = find(logo, logo+6, side);
		if(ptr == logo+6){
			cout << -1;
			return 0;
		}
		int idx = ptr - logo;
		int toPrint[6];
		int left[4];
		char val;
		if(idx % 2 == 0){
			toPrint[0] = logo[idx];
			toPrint[1] = logo[idx + 1];
			for(int i = idx; i < 6; i++){
				logo[i] = logo[i+1];
			}
			for(int i = idx; i < 6; i++){
				logo[i] = logo[i+1];
			}
			switch(idx/2){
				case 0:
					val = 'A';
					break;
				case 1:
					val = 'B';
					break;
				case 2:
					val = 'C';
					break;

			}

		} else {
			toPrint[0] = logo[idx];
			toPrint[1] = logo[idx - 1];
			for(int i = idx - 1; i < 6; i++){
				logo[i] = logo[i+1];
			}
			for(int i = idx - 1; i < 6; i++){
				logo[i] = logo[i+1];
			}
		}
		if(logo[0] + logo[2] == side && logo[1] == logo[3]  && logo[1] == side - toPrint[1]){
			toPrint[2] = logo[0];
			toPrint[3] = logo[1];
			toPrint[4] = logo[2];
			toPrint[5] = logo[3];
		} else if(logo[0] + logo[3] == side && logo[1] == logo[2] && logo[1] == side - toPrint[1]){
			toPrint[2] = logo[0];
			toPrint[3] = logo[1];
			toPrint[4] = logo[3];
			toPrint[5] = logo[2];
		} else if(logo[1] + logo[2] == side && logo[0] == logo[3] && logo[0] == side - toPrint[1]){
			toPrint[2] = logo[1];
			toPrint[3] = logo[0];
			toPrint[4] = logo[2];
			toPrint[5] = logo[3];
		} else if(logo[1] + logo[3] == side && logo[0] == logo[2] && logo[0] == side - toPrint[1]){
			toPrint[2] = logo[1];
			toPrint[3] = logo[0];
			toPrint[4] = logo[3];
			toPrint[5] = logo[2];
		} else {
			cout << -1;
			return 0;
		}
		cout << side << endl;
		for(int i = 0; i < toPrint[1]; i++){
			for(int i = 0; i < toPrint[0]; i++){
				switch(idx/2){
				case 0:
					cout << 'A';
					break;
				case 1:
					cout << 'B';
					break;
				case 2:
					cout << 'C';
					break;

				}
			}
			cout << endl;
		}

		for(int i = 0; i < toPrint[3]; i++){
			for(int i = 0; i < toPrint[2]; i++){
				switch(idx/2){
				case 0:
					cout << 'B';
					break;
				default:
					cout << 'A';
					break;

				}
				
			}
			for(int i = 0; i < toPrint[4]; i++){
				switch(idx/2){
				case 2:
					cout << 'B';
					break;
				default:
					cout << 'C';
					break;

				}
			}
			cout << endl;
		}

	}
	return 0;
}