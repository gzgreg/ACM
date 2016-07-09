#include <bits/stdtr1c++.h>

using namespace std;

int main(){
	int N; cin >> N;
	int array[N];
	for(int i = 0; i < N; i++){
		cin >> array[i];
		if(i > 0){
			if(array[i] < array[i-1]){
				cout << "no";
				return 0;
			}
		}
	}

	cout << "yes";
	return 0;
}