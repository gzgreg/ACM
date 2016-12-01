#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	string s; cin >> s;
	while(s != "0") {
		set<int> nums;
		for(int i = 1; i < s.size(); i++) {
			if(s[i] == '1') {
				for(int j = 2*i; j < s.size(); j += i) {
					if(s[j] == '1') {
						s[j] = '0';
					} else {
						s[j] = '1';
					}
				}
				nums.insert(i);
			}
		}

		for(int i : nums) {
			cout << i << " ";
		}
		cout << endl;

		cin >> s;
	}
	
	return 0;
}