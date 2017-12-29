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

		vector<string> strings;
		string tmp;
		while(str >> tmp) {
			sort(tmp.begin(), tmp.end());
			strings.push_back(tmp);
		}
		bool good = true;
		for(int i = 0; i < strings.size(); i++) {
			for(int j = i+1; j < strings.size(); j++) {
				if(strings[i] == strings[j]) {
					good = false;
				}
			}
		}
		ans += good;
	}

	cout << ans << endl;

	return 0;
}