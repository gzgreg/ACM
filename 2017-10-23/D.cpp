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
	
	string pass, s; cin >> pass >> s;

	map<char, int> later;

	for(char cur : pass) {
		later[cur]++;
	}

	int j = 0;

	for(int i = 0; i < s.size(); i++) {
		if(pass[j] == s[i]) {
			j++;
			later[s[i]]--;
		} else if (later[s[i]] > 0) {
			cout << "FAIL" << endl;
			return 0;
		}
	}

	if(j == pass.size()) {
		cout << "PASS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	return 0;
}