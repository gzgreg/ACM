#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	int ans = 0;
	while(getline(cin, s)) {
		stringstream str(s);
		vector<int> vals;
		int cur;
		while(str>>cur) {
			vals.push_back(cur);
		}
		
		for(int i = 0; i < vals.size(); i++) {
			for(int j = i+1; j < vals.size(); j++) {
				if(vals[i]>=vals[j] && vals[i]%vals[j] == 0) {
					cout << i << " " << j << endl;
					ans += vals[i]/vals[j];
				} else if(vals[j]>vals[i] && vals[j]%vals[i] == 0){
					cout << i << " " << j << endl;
					ans += vals[j]/vals[i];
				}
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}