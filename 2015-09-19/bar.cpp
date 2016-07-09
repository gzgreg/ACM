using namespace std;

#include <iostream>
#include <iomanip>
#include <algorithm>

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int n; cin >> n;
		int allLens[n];
		int len[n];
		int num[n];
		int totalLen = 0;
		int maxLen = 0;
		int curr;
		int baridx = 0;
		for(int j = 0; j < n; j++){
			cin >> allLens[j];
		}
		sort(allLens, allLens + n);
		for(int j = 0; j < n; j++){
			curr = allLens[j];
			if(j == 0){
				maxLen = curr;
			}
			if(curr > maxLen){
				num[baridx] = curr - maxLen;
				len[baridx] = totalLen;
				maxLen = curr;
				baridx++;
			}
			totalLen++;
		}
		for(int j = 0; j < baridx; j++){
			cout << num[j] << " " <<  len[j] << endl;
		}
	}	
}