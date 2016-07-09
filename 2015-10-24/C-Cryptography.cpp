#include <bits/stdc++.h>

using namespace std;

int main(){
	string n; cin >> n;
	int ans = 0;
	for(int i = 0; i < n.size(); i++){
		switch(i%3){
			case 0:
				if(n[i] != 'P') ans++;
				break;
			case 1:
				if(n[i] != 'E') ans++;
				break;
			case 2:
				if(n[i] != 'R') ans++;
				break;
		}
	}
	cout << ans;
	return 0;
}