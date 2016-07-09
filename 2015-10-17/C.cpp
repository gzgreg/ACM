//#include <bits/stdtr1c++.h>

#include <iostream>

using namespace std;

char path[] = {'p', 'a', 't', 'h'};

int main(){
	int N; cin >> N;

	for(int i = 0; i < N; i++){
		string s; cin >> s;
		int span = -1;
		int pFound = false;
		for(int j = s.size() - 4; j >= 0; j--){
			char curr = s[j];
			if(curr == 'p'){
				int idx = 1;
				for(int k = j + 1; k < s.size(); k++){
					if(s[k] == path[idx]){
						if(idx == 3){
							span = k - j + 1;
							pFound = true;
							break;
						} else {
							idx++;
						}
					}
				}
			}
			if(pFound) break;
		}
		cout << span << endl;
	}
	return 0;
}