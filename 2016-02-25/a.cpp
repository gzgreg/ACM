#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;

	string s; cin >> s;
	int total = 0;
	for(int i = 0; i < n; i++){
		int up = 0, left = 0;
		for(int j = i; j < n; j++){
			if(s[j] == 'U'){
				up++;
			} else if(s[j] == 'D'){
				up--;
			} else if(s[j] == 'L'){
				left++;
			} else if(s[j] == 'R'){
				left--;
			}
			if(left == 0 && up == 0){
				total++;
			}
		}
	}

	cout << total << endl;

	return 0;
}