using namespace std;

#include <iostream>
#include <iomanip>

int main(){
	int n;
	cin >> n;
	while(n != 0){
		int tim = 0;
		int tot = 0;
		int totD = 0;
		int minD = 60;
		for(int i = 0; i < n; i++){
			cin >> tim;
			totD += tim;
			if(tim < minD) minD = tim;
		}

		if(totD >= (n-1)*30) tot = totD + 30; else tot = n*30 + minD;
		
		cout << tot / 60 << ":" << setw(2) << setfill('0') << tot % 60 << endl;
		cin >> n;
	}	
}