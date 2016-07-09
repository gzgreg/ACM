#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

using namespace std;

int main(){
	int N; cin >> N;
	string curr;
	getline(cin, curr);
	for(int i = 0; i < N; i++){
		getline(cin, curr);
		int found = curr.find("Simon says");
		if(found == 0){
			string newS = curr.erase(0, 10);
			cout << newS << endl;
		}
	}
	return 0;
}