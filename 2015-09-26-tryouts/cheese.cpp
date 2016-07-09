using namespace std;

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

int main(){
	int n;
	cin >> n;
	while(n != 0){
		int cheeses[3];
		cheeses[0] = 0; cheeses[1] = 0; cheeses[2] = 0;
		for (int i = 0; i < n; i++){
			string s;
			cin >> s;
			if(s == "Cheddar"){
				cheeses[0]++;
			} else if(s == "Gouda"){
				cheeses[1]++;
			} else if(s == "Havarti"){
				cheeses[2]++;
			}
		}
		sort(cheeses, cheeses+3);
		cout << max(max(cheeses[0] * 3, cheeses[1] * 2), cheeses[2]) << endl;
		cin >> n;
	}
	return 0;
}