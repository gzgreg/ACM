#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	while(T--){
		int Q, K; cin >> Q >> K;
		int num = 0;
		multiset<int> vals;
		int xorVal = 0;
		for(int i = 0; i < Q; i++){
			string s; cin >> s;
			if(s == "insert"){
				int curr; cin >> curr;
				if(vals.size() == 0){
					xorVal = curr;
					vals.insert(curr);
				} else {
					if(vals.size() >= K && *(vals.begin()) <= curr){
						int toRemove = *(vals.begin());
						vals.erase(vals.begin());
						xorVal = xorVal^toRemove;
						xorVal = xorVal^curr;
						vals.insert(curr);
					} else if(vals.size() < K){
						xorVal = xorVal^curr;
						vals.insert(curr);
					}
					
				}
			} else {
				cout << xorVal << endl;
			}
		}
	}

	return 0;
}