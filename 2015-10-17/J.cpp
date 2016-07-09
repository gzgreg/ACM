//#include <bits/stdtr1c++.h>

#include <iostream>

using namespace std;

int main(){
	int N; cin >> N;

	for(int i = 0; i < N; i++){
		int lhs, rhs; cin >> lhs >> rhs;
		string op; cin >> op;
		if(op == "<"){
			if(lhs < rhs){
				cout << "Ready" << endl;
			} else {
				cout << "Reboot" << endl;
			}
		} else if(op == ">"){
			if(lhs > rhs){
				cout << "Ready" << endl;
			} else {
				cout << "Reboot" << endl;
			}
		}
	}
	return 0;
}