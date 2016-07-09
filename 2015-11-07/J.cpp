#include <bits/stdc++.h>

using namespace std;

string strings[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

int main(){
	long long n;
	while(cin >> n){
		bool seen[10] = {false};
		int numSeen = 0;
		int mult = 1;
		while(numSeen < 10){
			stringstream sval; sval << n * mult;
			string currVal = sval.str();
			for(int i = 0; i < 10; i++){
				if(!seen[i]){
					if(currVal.find(strings[i]) != string::npos){
						seen[i] = true;
						numSeen++;
					}
				}
			}
			mult++;
		}
		cout << mult - 1 << endl;
	}
	return 0;
}